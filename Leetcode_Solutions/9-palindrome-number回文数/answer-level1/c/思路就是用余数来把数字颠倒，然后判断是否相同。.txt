### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x){
    int tem=x;
    if(x<0)
    return false;
    long resum=0;
    while(tem!=0)
    {
        resum=resum*10+tem%10;
        tem=tem/10;
    }
   return x==resum?true:false;

}
```