### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_119_getRow.java)

### 代码

```java
class Solution {
     /**
     * 解题思路：
     * 最简单的就是像 {@link _118_generate} 中解题方式，求出第row行的结果，可是期望 O(k) 空间复杂度，这是难点
     * 考虑能不能通过规律找出直接计算第row行的结果？
     * 通过杨辉三角规律可知，第i行第j个得数字结果是(i,j)的组合数
     * 
     * 执行用时 :1 ms, 在所有 java 提交中击败了93.68%的用户
     * 内存消耗 :33.6 MB, 在所有 java 提交中击败了23.63%的用户
     * @param rowIndex
     * @return
     */
    public List<Integer> getRow(int rowIndex) {
        List<Integer> retList = new ArrayList<>();
        int N = rowIndex;
        long pre = 1;
        retList.add(1);
        for (int k = 1; k <= N; k++) {
            long cur = pre * (N - k + 1) / k;
            retList.add((int) cur);
            pre = cur;
        }
        return retList;
    }
}
```