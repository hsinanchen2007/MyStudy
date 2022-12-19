### 解题思路
直接构建ans数组 按距离远近(level)进行排序
`执行用时 : 4 ms , 在所有 Java 提交中击败了 100.00% 的用户`
`内存消耗 : 39.8 MB, 在所有 Java 提交中击败了100.00% 的用户`

### 代码

```java
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int count = R * C, level = 1, num = 0;
        int[][] ans = new int[count][2];
        ans[num][0] = r0; ans[num++][1] = c0;
        while(num < count) {
            for (int i = 0; i <= level; i++) {
                int j = level - i;
                if (r0 + i < R ) {
                    if (c0 + j < C) {ans[num][0] = r0 + i; ans[num++][1] = c0 + j;}
                    if (c0 - j >= 0 && j != 0) {ans[num][0] = r0 + i; ans[num++][1] = c0 - j;}
                }
                if (r0 - i >= 0 && i != 0) {
                    if (c0 + j < C) {ans[num][0] = r0 - i; ans[num++][1] = c0 + j;}
                    if (c0 - j >= 0 && j != 0) {ans[num][0] = r0 - i; ans[num++][1] = c0 - j;}
                }
            }
            level++;
        }
        return ans;
    }
}
```