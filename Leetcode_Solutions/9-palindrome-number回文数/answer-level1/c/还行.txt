### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x){
    long y=0;int x1=x;
    if(x<0)
        return false;
    else{
        while(x!=0){
            y=10*y+x%10;
            x/=10;
        }
        if(x1==y)
            return true;
        else
            return false;
    }
}
```