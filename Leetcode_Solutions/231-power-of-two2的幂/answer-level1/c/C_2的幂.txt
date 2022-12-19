### 解题思路
两行代码通过
### 代码

```c
bool isPowerOfTwo(int n){
    while(n%2==0&&n!=0)n/=2;
    return n==1&&n!=0;
}
```