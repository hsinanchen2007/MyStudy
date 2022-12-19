# 代码
```java
class Solution {
    private int res, global_k;

    public int kthToLast(ListNode head, int k) {
        global_k = k;
        dfs(head);
        return res;
    }

    private void dfs(ListNode node) {
        if (node == null)
            return;
        dfs(node.next);
        if (--global_k == 0)
            res = node.val;
    }
}
```
