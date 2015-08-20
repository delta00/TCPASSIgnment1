#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

main()
{

FILE *fp;
char returnData[64];
fp = popen("/sbin/ifconfig | awk '/^eth/{s=$1;getline;print $1,$2}'", "r");
while (fgets(returnData, 64, fp) != NULL)
{
printf("The %s", returnData);
}
pclose(fp);

}