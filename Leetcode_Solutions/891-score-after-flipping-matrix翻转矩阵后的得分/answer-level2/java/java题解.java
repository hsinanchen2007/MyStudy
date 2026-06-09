思路：查看行是否需要翻转，之后看列是否需要翻转。

具体做法：我们怎么知道每一行是否需要翻转达到最优呢？很简单，只需要看最高位是否为1，即题目的A[r][0] == 1 ?等于1的时候不用翻转，0则需要翻转。我们假设数组长度为C，当最高为为1时，不管后面(C - 1)是1是0，这个数最小值至少为`2^(C-1)` 。而当最高位为0时，尽管后面全是1，最大也是`2^(C - 1) - 1`。所以当最高位为1时，行最优。

而列就比较简单了，假设一列有R个数，有count个1，当`count < R - count`时需要翻转。

```
class Solution {
    public int matrixScore(int[][] A) {
        int row = A.length, col = A[0].length;
        int ans = 0;
        for(int c = 0; c < col; ++c){
            int count = 0;
            for(int r = 0; r < row; ++r){
                //行翻转加计算列1的个数
                //虽然这里找的是0的个数，但并不影响
                count += A[r][c] ^ A[r][0];
            }
            //列翻转
            if(count < row - count) count = row - count;
            ans += count * (1 << (col - c - 1));
        }
        return ans;
    }
}
```
时间复杂度为`O(row * col)`
空间复杂度为`O(1)`
