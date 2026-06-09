### 解题思路
![Snipaste_2020-03-27_15-23-24.png](https://pic.leetcode-cn.com/8604d6b7b0cb70f21d02fb9c93a7ed0e0c8d76cbadda4d3ad229162d454806d3-Snipaste_2020-03-27_15-23-24.png)
常规的位运算思路：不断判断末位是否为1，同时右移数字。

### 代码

```c
int hammingWeight(uint32_t n) {
    int count=0;
    for(int i=0;i<32;i++){
        if(n&1==1) count++;
        n>>=1;
    }
    return count;
}
```