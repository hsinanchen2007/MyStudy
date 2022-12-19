int maximum69Number (int num){
int i,t=0,n=num;
for(i=1;n>1;i++,n/=10)
{if(n%10==6)
 {t=i;}}
return(num+3*pow(10,t-1));
}