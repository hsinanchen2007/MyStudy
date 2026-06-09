执行用时 :6 ms, 在所有 Java 提交中击败了95.94%的用户
内存消耗 :46.4 MB, 在所有 Java 提交中击败了84.31%的用户

```
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[] map = new int[40000];
        for (int a: A) {
            ++map[a];
        }
        int res = 0, left = 0;
        for (int m: map) {
            res += left;
            left += m;
            left -= left > 0 ? 1 : 0;
        }
        res += (1 + left) * left / 2;
        return res;
    }
}
```
