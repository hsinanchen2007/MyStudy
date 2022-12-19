### 解题思路
我的思路就是，一个方法三个参数，k个数、拼凑成n,从<code>start</code>到9这几个数中选。

执行用时 :1 ms, 在所有 java 提交中击败了98.94%的用户
内存消耗 :33.4 MB, 在所有 java 提交中击败了33.94%的用户

### 代码

```java
class Solution {

    List<List<Integer>> ans = new ArrayList<>();
    //尽量不要使用遗留类Stack,Deque完成可以实现Stack功能。
    Deque<Integer> path = new ArrayDeque<>();

    /**
     * 整体思路
     *
     * @param k k个数
     * @param n 组合成n（累加和为n)
     *          组合数范围1~9，且不重复
     * @return
     */
    public List<List<Integer>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }

    /**
     * @param k     k个数
     * @param n     组合成n（累加和为n)
     * @param start 组合数范围start~9，且不重复
     */
    private void dfs(int k, int n, int start) {
        if (k < 0 || n < 0) return;   // 剪枝

        // 刚好k个数、刚好递减成0（说明这k个数累加和刚好为n)
        if (k == 0 && n == 0) {
            if (!path.isEmpty())
                ans.add(new ArrayList<>(path));
            return;
        }

        // 从start开始，到9的范围，然后就是递归分支（选、不选) 记得恢复状态
        for (int i = start; i < 10; i++) {
            path.push(i);
            dfs(k - 1, n - i, ++start);
            path.pop();
        }
    }
}
```