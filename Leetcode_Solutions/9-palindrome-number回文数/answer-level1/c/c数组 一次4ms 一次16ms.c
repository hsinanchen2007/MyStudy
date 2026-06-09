bool isPalindrome(int x)
{
if(x==0)
return true;
if(x<0 || x%10==0)
return false;

int a[11]={0};
int i=0,j=0;
while(x!=0)
{
a[i++]=x%10;
x=x/10;
}
i--;
while(j<=i)
{
 if(a[i--]!=a[j++])
return false;
}   
return true; 
}