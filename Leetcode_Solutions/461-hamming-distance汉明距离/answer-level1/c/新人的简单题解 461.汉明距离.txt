### 解题思路
位运算，先异或。然后统计异或结果1的个数就好。

### 代码

```c
int hammingDistance(int x, int y){
    int k=x^y;
    int res=0;
    for(int i=0;i<32;i++)
    {
        res+=(k&1);
        k>>=1;
    }
    return res;
}
```