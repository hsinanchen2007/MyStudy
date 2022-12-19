首先确定已知量为硬币的数量 n ，未知量为拥有完整的硬币数量的行数 i。

    根据规律易得：前 i 行完整的硬币数量为 (i+1)*i/2 ，前i+1行则为 (i+2)*(i+1)/2 。
    从而可得： (i+1)*i/2 ≤ n < (i+2)*(i+1)/2
    计算可得i的范围为：sqrt(2n + 0.25)-1.5 < n ≤ sqrt(2n + 0.25) - 0.5
    由此可见，i范围的上下限的差距小于1，且Java语言采用退一法，从而输出i范围的上限（整型）即可

（PS：n为int类型，2n可能超过int的范围，因此需要先将其转化为double类型进行处理） 

```
class Solution {
    public int arrangeCoins(int n) {
        return (int)(Math.sqrt(2 * (double)n + 0.25) - 0.5);
    }
}
```


