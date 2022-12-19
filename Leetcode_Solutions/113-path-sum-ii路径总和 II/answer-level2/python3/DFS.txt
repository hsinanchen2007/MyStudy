## 思路:

和上一题一样, 用DFS只不过在遍历时候,要记录`val`而已

```python [1]
def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        if not root: return []
        def helper(root,sum, tmp):
            if not root:
                return 
            if not root.left and not root.right and sum - root.val == 0 :
                tmp += [root.val]
                res.append(tmp)
                return 
            helper(root.left, sum - root.val, tmp + [root.val])
            helper(root.right, sum - root.val, tmp + [root.val])
        helper(root, sum, [])
        return res
```



```java [1]
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        helper(root, sum, res, new ArrayList<Integer>());
        return res;
    }

    private void helper(TreeNode root, int sum, List<List<Integer>> res, ArrayList<Integer> tmp) {
        if (root == null) return;
        tmp.add(root.val);
        if (root.left == null && root.right == null && sum - root.val == 0) res.add(new ArrayList<>(tmp));
        helper(root.left, sum - root.val, res, tmp);
        helper(root.right, sum - root.val, res, tmp);
        tmp.remove(tmp.size() - 1);
    }
}
```

相关题型 : [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)