### 解题思路
今天是第一次使用leetCode，第一次运行出错了，原因在于将变量定义为 int型了，改成long就对了

### 代码

```c
bool isPalindrome(int x){
if(x<0) return false;
else 
{
    long i=0,k,j;
    for(k=x;k!=0;k=k/10)
    {
        j=k%10;
        i=i*10+j;

    }
    if(i==x)
   return true;
    else return false;
}
}
```