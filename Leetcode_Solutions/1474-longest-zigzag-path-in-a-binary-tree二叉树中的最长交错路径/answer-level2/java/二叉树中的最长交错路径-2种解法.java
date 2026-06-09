>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：记忆化搜索

时间复杂度是O(n)，其中n为树中的节点个数。空间复杂度是O(h)，其中h为树的高度。

执行用时：81ms，击败100.00%。消耗内存62.7MB，击败100.00%。

```java
public class Solution {
    private Map<TreeNode, Integer> leftMap = new HashMap<>(), rightMap = new HashMap<>(), map = new HashMap<>();

    public int longestZigZag(TreeNode root) {
        return longestZigZag(root, 0) - 1;
    }

    //last = -1代表上一步是往左走的，last = 1代表上一步是往右走的，last = 0表示这是路径中的第一个节点，没有上一步
    private int longestZigZag(TreeNode root, int last) {
        if (last == -1 && leftMap.containsKey(root)) {
            return leftMap.get(root);
        } else if (last == 1 && rightMap.containsKey(root)) {
            return rightMap.get(root);
        } else if (last == 0 && map.containsKey(root)) {
            return map.get(root);
        }
        if (null == root) {
            return 0;
        }
        if (last == 1) {
            int result = 1 + longestZigZag(root.left, -1);
            rightMap.put(root, result);
            return result;
        } else if (last == -1) {
            int result = 1 + longestZigZag(root.right, 1);
            leftMap.put(root, result);
            return result;
        }
        int result = Math.max(1 + Math.max(longestZigZag(root.left, -1), longestZigZag(root.right, 1)),
                Math.max(longestZigZag(root.left, 0), longestZigZag(root.right, 0)));
        map.put(root, result);
        return result;
    }
}
```

# 解法二：深度优先遍历

时间复杂度是O(n)，其中n为树中的节点个数。空间复杂度是O(h)，其中h为树的高度。

执行用时：6ms，击败100.00%。消耗内存53.8MB，击败100.00%。

```java
public class Solution {
    private int result;

    public int longestZigZag(TreeNode root) {
        dfs(root.left, -1, 1);
        dfs(root.right, 1, 1);
        return result;
    }

    private void dfs(TreeNode root, int last, int len) {
        if (null == root) {
            return;
        }
        result = Math.max(result, len);
        if (last == -1) {
            dfs(root.left, -1, 1);
            dfs(root.right, 1, len + 1);
        } else {
            dfs(root.left, -1, len + 1);
            dfs(root.right, 1, 1);
        }
    }
}
```