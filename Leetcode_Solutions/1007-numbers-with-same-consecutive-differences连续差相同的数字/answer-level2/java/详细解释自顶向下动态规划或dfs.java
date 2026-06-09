## 分析：

- 动态规划，自顶向下。其实就是dfs。
- 我们用队列的思想从最高位一个一个加进去，注意最高位除了N是1的情况都不可能是0。而N如果是1，那么答案必为`0,1,2,3,4,5,6,7,8,9`。
- 每次我们有两个选择，就是两个值相差为K。

## 代码：

```java
class Solution {
    List<Integer> ans;
    public int[] numsSameConsecDiff(int N, int K) {
        ans = new ArrayList();
        if (N == 1) return new int[] {0,1,2,3,4,5,6,7,8,9};
        for (int i = 1; i < 10; i++) dfs(i, i, N - 1, K);
        int len = ans.size();
        int[] res = new int[len];
        for (int i = 0; i < len; i++) res[i] = ans.get(i);
        return res;
    }

    public void dfs(int val, int pre, int N, int K) {// pre 是前一位的值，val是目前的总值
        if (N <= 0) {
            ans.add(val);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (pre - i == K || i - pre == K) { // 将当前位和前一位相比，是否相差K
                dfs(val * 10 + i, i, N - 1, K); // 符合条件就把当前位加入个位，其他位都向左移一位
            }
        }
    }
}
```