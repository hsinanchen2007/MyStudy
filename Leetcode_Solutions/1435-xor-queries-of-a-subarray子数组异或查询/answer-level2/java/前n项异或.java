### 解题思路
类比数组前n项和。
由于相同两个数异或等于0，而0与任何数异或又等于该数本身
所以区间[l, r]之间的异或结果XOR[l, r]也就等于区间[0, r]之间的异或结果XOR[0, r]再与区间[0, l-1]之间的异或结果XOR[0, l-1]再进行异或。公式如下：

`XOR[l, r] = XOR[0, r] ^ XOR[0, l-1]`

### 代码

```java
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] xor = new int[arr.length+1];
        for(int i = 0; i < arr.length; i++){
            xor[i+1] = xor[i]^arr[i];
        }
        int[] ans = new int[queries.length];
        int i = 0;
        for(int[] query : queries){
            int l = query[0], r = query[1];
            ans[i++] = xor[r+1]^xor[l];
        }
        return ans;
    }
}
```