### 解题思路
此处撰写解题思路
利用整数反转，反转后是否和原数相等从而得出是否是回文数
### 代码

```c
bool isPalindrome(int x){
if(x<0) return false;
if(x>=0&&x<10) return true;
if(x%10==0) return false;
long res=0;
int temp=x;
while(x!=0)
{
    res=res*10+x%10;
    x/=10;
}
if(temp==res) return true;
 else return false;
}
```