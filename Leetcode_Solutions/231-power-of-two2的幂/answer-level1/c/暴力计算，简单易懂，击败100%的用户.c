### 解题思路
此处撰写解题思路

### 代码

```c
bool isPowerOfTwo(int n){
    if(n==1)
    return true;
    long long ans=1;
    while(ans<n)
    ans*=2;
    if(ans==n)
    return true;
    return false;
}
```