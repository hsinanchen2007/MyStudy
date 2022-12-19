### 解题思路
通过递归解决层次遍历问题

### 代码

```java
class Solution {
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        zigzagLevelOrder(root, result, 0);
        return result;
    }

    private void zigzagLevelOrder(TreeNode curr, List<List<Integer>> result, int level) {
        if (curr == null) {
            return;
        }

        if (result.size() <= level) {
            List<Integer> currLevelvals = new LinkedList<>();

            result.add(currLevelvals);
        }
        List<Integer> currLevelvals = result.get(level);
        if (level % 2 == 0) {
            currLevelvals.add(curr.val);
        }else{
            currLevelvals.add(0,curr.val);
        }

        zigzagLevelOrder(curr.left, result, level+1);
        zigzagLevelOrder(curr.right, result, level+1);
    }
}
```