### 解题思路
此处撰写解题思路
1.x<0 false 
2.求x回文m 
3.判断x==m
### 代码

```c
bool isPalindrome(int x){
    if(x<0) return false;
    long m=0;
    int n=x;
    while(n){
        m=m*10+n%10;
        n/=10;
    }
    return m==x;
}
```