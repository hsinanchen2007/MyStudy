执行用时 :4 ms, 在所有 c 提交中击败了83.88%的用户
内存消耗 :6.9 MB, 在所有 c 提交中击败了70.56%的用户

#include<math.h>
int myAtoi(char * str){
    long int sum=0;
    char *p=str;
    int flag=0;
    if(p==0)return 0;
    while(*p==' ')p++;
    if(*p=='-'){flag=1;p++;}
    else if(*p=='+'){flag=0;p++;}                                    //跳过所有的空格，
    else if(*p!='-'&&!(*p>='0'&&*p<='9')||p==0)return 0;          
    while(*p)
    {   
        int s=*p-'0';
        if(*p>='0'&&*p<='9')sum=sum*10+s;
        else break;                                                    //如果中间有特殊符号，直接跳出
        if(sum>pow(2,31)-1&&flag==0)return pow(2,31)-1;              //中途溢出，直接返回
        else if(flag==1&&-sum<pow(2,31)*-1)return -pow(2,31);
        
        p++;
    }
    if(flag==1)sum=-sum;
    return sum;
}