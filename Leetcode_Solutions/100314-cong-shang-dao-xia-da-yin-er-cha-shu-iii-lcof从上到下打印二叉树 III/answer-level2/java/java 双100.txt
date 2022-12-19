### 解题思路
核心思想还是广度优先遍历；同时使用双端队列，解决左右互换遍历问题

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
        LinkedList<TreeNode>queue=new LinkedList<>();
        List<List<Integer>> result=new ArrayList<>();
        if(root==null){
            return result;
        }
        queue.add(root);
        //index为偶数表示从左到右；为奇数表示从右到从
        int index=0;
        while(!queue.isEmpty()){
            List<Integer>resTmp=new ArrayList<>();
            for(int i=queue.size();i>0;i--){
                if((index&1)==0){
                    //从左向右时，所有的操作均从属一般的广度优先遍历即可
                    TreeNode tmpNode=queue.poll();
                    resTmp.add(tmpNode.val);
                    if(tmpNode.left!=null){
                        queue.add(tmpNode.left);
                    }
                    if(tmpNode.right!=null){
                        queue.add(tmpNode.right);
                    }
                }else{
                    //从右向左时，需反向获取元素
                    TreeNode tmpNode=queue.pollLast();
                    resTmp.add(tmpNode.val);
                    //反向填充元素，同时left和right添加顺序也需要互换（此处稍微复杂，在纸上模拟下即可）
                    if(tmpNode.right!=null){
                        queue.addFirst(tmpNode.right);
                    }
                    if(tmpNode.left!=null){
                        queue.addFirst(tmpNode.left);
                    }
                }
            }
            index++;
            result.add(resTmp);
        }
        return result;
    }
}
```