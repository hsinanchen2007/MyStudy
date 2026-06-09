### 解题思路
此处撰写解题思路

先排除负数,再除掉各位数,int的上限大约2000000000以上,回文只要开头比2大就不行,然后根据参数取模,然后再构建相反的回文数字,最后比较是否大小相等


### 代码

```c
bool isPalindrome(int x){
    if(x<0)
        return false;
    if(x>0&&x<10)
        return true;
    if(x>1000000000&&x%10>2)
        return false;

    int temp=x;
    int y=0;
    int  s=10;
    while(temp!=0)
    {
        y=y*s+temp%s;
        temp=temp/s;
    }
   if(x==y) 
        return true;
    else 
        return false;


}
```