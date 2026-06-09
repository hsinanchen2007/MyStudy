### 解题思路
通过位运算，计算数二进制中1的个数
2的幂次方二进制中只含有1个1

### 代码

```c
bool isPowerOfTwo(int n){
    if(n<=0) return false;
    int count=0;
    while(n!=0){
        n=n&(n-1);      //统计二进制中1的个数
        count++;
    }
    if(count==1) return true;
    return false;
}
```