### 解题思路
用时1ms
主要归功于LinkedList的addFirst()方法，直接从最前面插入元素

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> list = new LinkedList<>();
        List<Integer> levelList = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode cur = new TreeNode(0);
        if (root != null){
            queue.offer(root);
        }
        while (!queue.isEmpty()){
            if (!levelList.isEmpty()){
                list.addFirst(levelList);
            }
            int count = 0;
            int levelCount = queue.size();
            levelList = new ArrayList<>();
            while(count++ < levelCount){
                cur = queue.poll();
                levelList.add(cur.val);
                if (cur.left != null){
                    queue.offer(cur.left);
                }
                if (cur.right != null){
                    queue.offer(cur.right);
                }
            }
        }
        if (!levelList.isEmpty()){
            list.addFirst(levelList);
        }
        return list;
    }
}
```