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

int total(bills * cash){
	return cash->hundred*100 + cash->fifty*50 + cash->twenty*20 + cash->ten*10 +
	cash->five*5 + cash->two*2 + cash->one + cash->quarter*0.25 + cash->dime*0.1 + cash->nickel*0.05 + cash->penny*0.01;
}

bills pull_out(bills * money){
	bills earnedbills;
	if(money->earned){
		if(money->earned/100 && money->hundred)
			;
		
	}
	
	
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
	printf("total money earned = %4.2f", cash.earned);
	bills pulled = pull_out(&cash);
}
