### 解题思路
需注意边界问题：
1.负数问题
2.“回文操作”溢出

### 代码

```c
bool isPalindrome(int x){
    if(x<0)
        return false;

    long y=0;
    int temp=x;
    while(temp!=0){
        y=y*10+temp%10;
        temp/=10;
    }
    if(y==x)
        return true;
    return false;
}
```