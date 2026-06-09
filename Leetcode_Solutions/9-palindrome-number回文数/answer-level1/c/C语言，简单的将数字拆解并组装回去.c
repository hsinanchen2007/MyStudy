### 解题思路
并没有用什么高大上的方法，由题意可以容易的知道，只要是小于0的数，都不可能是回文数，所以只要是负数就返回false。
是正数的话，就将数从个位开始拆解，然后重新组装。组装后再与输入的值进行对比，相同就返回ture,不相同就返回false;

### 代码

```c
bool isPalindrome(int x)
{
    int n,tem;
    long int m=0;
    tem=x;
    if(x<0)
    return false;
    while(x>0)
    {
        n=x%10;
        m=m*10+n;
        x/=10;

    }
     if(m==tem)
        return true;
     else
     return false;
}
```