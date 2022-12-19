### 解题思路
根据二叉树的**层序遍历**过程，修改即可。
遍历每一层的时候，得到当前层的宽度，即为size;
遍历size，得到每一层的总和sum，然后将sum/size的平均值压入栈中。
不懂的可以先查查层序遍历的算法。

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
    public List<Double> averageOfLevels(TreeNode root) {
             if(root==null) return null;
        List<Double> doubleList = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            //当前层的和
            double sum = 0;
            //记录当前队列长度
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode tempNode = q.poll();//出队列操作
                sum+=tempNode.val;//计算和

                if(tempNode.left!=null){
                    q.add(tempNode.left);
                }
                if(tempNode.right!=null){
                    q.add(tempNode.right);
                }
            }
            doubleList.add(sum/size);

        }
        return doubleList;
    }
}
```