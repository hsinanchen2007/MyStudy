### 解题思路
如题，有了层次遍历的基础之后，采用队列的方法记录每一行，通过在遍历时，先判断当前行是奇数还是偶数，来决定遍历方式是顺序还是逆序，即可实现。

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<>();
        if(root == null) return levels;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;
        while(!queue.isEmpty()){
            int level_size = queue.size();

            //锯齿实现，根据当前level %2值
            List<Integer> tmpLevel = new ArrayList<>();
            for(int i=0;i<level_size;i++){
                TreeNode node = queue.remove();
                tmpLevel.add(node.val);

                if(node.left!=null) queue.add(node.left);
                if(node.right!=null) queue.add(node.right);
            }

            if(level % 2 == 0){
                levels.add(tmpLevel);
            }else{
                List<Integer> tmpLevel1 = new ArrayList<>();
                for(int i=tmpLevel.size()-1;i>=0;i--){
                    tmpLevel1.add(tmpLevel.get(i));
                }
                levels.add(tmpLevel1);
            }
            level++;
        }
        return levels;
    }
}
```