### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x)
{
  int temp=x;
  if(x<0)
    return false;
  else
{
    
 long num=0;
while(x)
{
    num=num*10+x%10;
    x=x/10;
}
if(temp==num)
return true;
else return false;
}
}
```