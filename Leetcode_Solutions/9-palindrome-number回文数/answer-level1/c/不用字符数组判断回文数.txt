### 解题思路
求x的逆序数ux，判断x是否等于ux

### 代码

```c
bool isPalindrome(int x){
    if(x<0)
        return false;
    long int ux=0,a=x;
    int i;
    while(a/10)
    {
       ux*=10;
       ux+=a%10;
       a/=10;
    }
	ux*=10;
    ux+=a%10;
    if(x==ux) return true;
    else return false;
}
```