#include "cashout.h"

void checkearned(bills * money){
	if(money->leave > money->total){
		printf("error: total money is less than what to leave in the register");
		exit(0);
	}
}

int assign(char * buf){
	fgets(buf,200,stdin);
	return atoi(buf);
}

double total(bills * cash){	
	return cash->hundred*100 + cash->fifty*50 + cash->twenty*20 + cash->ten*10 +
	cash->five*5 + cash->two*2 + cash->one*1 + cash->quarter*0.25 + cash->dime*0.1 + cash->nickel*0.05 + cash->penny*0.01;
}

void init_bills(bills * money){
	money->hundred = 0;
	money->fifty = 0;
	money->twenty = 0;
	money->ten = 0;
	money->five = 0;
	money->two = 0;
	money->one = 0;
	money->quarter = 0;
	money->dime = 0;
	money->nickel = 0;
	money->penny = 0;
}

void print_bills(char * message, bills * money, int mode){
	printf("%s\n", message);
	if(money->hundred)
		printf("%d hundreds\n",money->hundred);
	if(money->fifty)
		printf("%d fifties\n",money->fifty);
	if(money->twenty)
		printf("%d twenties\n",money->twenty);
	if(money->ten)
		printf("%d tens\n",money->ten);
	if(money->five)
		printf("%d fives\n",money->five);
	if(money->two)
		printf("%d twos\n",money->two);
	if(money->one)
		printf("%d ones\n",money->one);
	if(money->quarter)
		printf("%d quarters\n",money->quarter);
	if(money->dime)
		printf("%d dimes\n",money->dime);
	if(money->nickel)
		printf("%d nickels\n",money->nickel);
	if(money->penny)
		printf("%d pennies\n",money->penny);
	printf("%4.2f total money\n", money->total);
	if(mode){
		printf("%d$ to leave in the register\n", money->leave);
		printf("%4.2f$ earned\n", money->earned);
	}
	
}

bills pull_out(bills * money){
	bills earnedbills;
	init_bills(&earnedbills);
	earnedbills.earned = money->earned;
	money->total -= money->earned;
	if(money->earned){
		if(money->earned/100 >= 1 && money->earned/100){
			earnedbills.hundred = money->earned/100;
			money->hundred -= (int)money->earned/100;
			money->earned -= earnedbills.hundred * 100;
		}
		if(money->earned/50 >= 1 && money->fifty){
			earnedbills.fifty = money->earned/50;
			money->fifty -= (int)money->earned/50;
			money->earned -= earnedbills.fifty * 50;
		}
		if(money->earned/20 >= 1 && money->twenty){
			earnedbills.twenty = money->earned/20;
			money->twenty -= (int)money->earned/20;
			money->earned -= earnedbills.twenty * 20;
		}
		if(money->earned/10 >= 1 && money->ten){
			earnedbills.ten = money->earned/10;
			money->ten -= (int)money->earned/10;
			money->earned -= earnedbills.ten * 10;
		}
		if(money->earned/5 >= 1 && money->five){
			earnedbills.five = money->earned/5;
			money->five -= (int)money->earned/5;
			money->earned -= earnedbills.five * 5;
		}
		if(money->earned/2 >= 1 && money->two){
			earnedbills.two = money->earned/2;
			money->two -= (int)money->earned/2;
			money->earned -= earnedbills.two * 2;
		}
		if(money->earned/1 >= 1 && money->one){
			earnedbills.one = money->earned/1;
			money->one -= (int)money->earned/1;
			money->earned -= earnedbills.one * 1;
		}	
		if(money->earned/0.25 >= 1 && money->quarter){
			earnedbills.quarter = money->earned/0.25;
			money->quarter -= (int)(money->earned/0.25);
			money->earned -= earnedbills.quarter * 0.25;
		}	
		if(money->earned/0.1 >= 1 && money->dime){
			earnedbills.dime = money->earned/0.10;
			money->dime -= (int)(money->earned/0.10);
			money->earned -= earnedbills.dime * 0.10;
		}	
		//printf("\n mmmmmmmmmm %4.2f earned %d nickels\n",money->earned/0.05, money->nickel);
		if(money->earned/0.05 >= 1 && money->nickel){
			earnedbills.nickel = money->earned/0.05;
			money->nickel -= (int)(money->earned/0.05);
			money->earned -= earnedbills.nickel * 0.05;
		}
		//printf("\n mmmmmmmmmm %4.2f earned %d pennies\n",money->earned/0.01, money->penny);	
		if(money->earned/0.01 >= 1 && money->penny){
			earnedbills.penny = money->earned/0.01;
			money->penny -= (int)(money->earned/0.01);
			money->earned -= earnedbills.penny * 0.01;
		}	
	}
	earnedbills.total = total(&earnedbills);
	money->total = total(money);
	return earnedbills;
}

void populate_bills(){
	char buf[200];
	int forbills;
	bills cash;
	printf("how much money to leave in the register?\n");
	cash.leave = assign(buf);
	printf("how many 100$s?\n");
	cash.hundred = assign(buf);
	printf("how many 50$s?\n");
	cash.fifty = assign(buf);
	printf("how many 20$s?\n");
	cash.twenty = assign(buf);
	printf("how many 10$s?\n");
	cash.ten = assign(buf);
	printf("how many 5$s?\n");
	cash.five = assign(buf);
	printf("how many 2$s?\n");
	cash.two = assign(buf);
	printf("how many 1$s?\n");
	cash.one = assign(buf);
	printf("how many quarters?\n");
	cash.quarter = assign(buf);
	printf("how many dimes?\n");
	cash.dime = assign(buf);
	printf("how many nickels?\n");
	cash.nickel = assign(buf);
	printf("how many pennies?\n");
	cash.penny = assign(buf);
	cash.total = total(&cash);
	checkearned(&cash);
	cash.earned = cash.total - cash.leave;
	printf("total money in register= %4.2f\n", cash.total);
	printf("total money earned = %4.2f\n", cash.earned);
	
	print_bills("\nmoney currently in the register", &cash, 1);
	bills pulled = pull_out(&cash);
	print_bills("\nwhat to leave in the register", &cash, 1);
	print_bills("\nmoney to take out", &pulled, 0);
}
