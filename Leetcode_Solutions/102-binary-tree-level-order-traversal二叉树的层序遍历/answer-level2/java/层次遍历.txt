### 解题思路
用时1ms
层次遍历，用一个list存储每层的元素

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> levelList = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode cur = new TreeNode(0);
        if (root != null){
            queue.offer(root);
        }   
        while (!queue.isEmpty()){
            if (levelList.size() != 0){
                list.add(levelList);
            }
            int curLevelCount = queue.size();
            int count = 0;
            levelList = new ArrayList<>();
            while (count++ < curLevelCount){
                cur = queue.poll();
                levelList.add(cur.val);
                if(cur.left != null){
                    queue.offer(cur.left);
                }
                if(cur.right != null){
                    queue.offer(cur.right);
                }
            }
        }
        if (levelList.size() != 0){
            list.add(levelList);
        }
        return list;
    }
}
```