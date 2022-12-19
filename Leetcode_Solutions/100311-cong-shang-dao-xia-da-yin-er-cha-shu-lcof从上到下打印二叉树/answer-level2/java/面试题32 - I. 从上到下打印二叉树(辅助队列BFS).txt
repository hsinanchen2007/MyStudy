### 解题思路
就是树的层次遍历，用BFS就行了，循环次数是树高，主要思想
1.根节点入队
2.判断队列是否空
2.1空就结束（代表所有节点都输出了）
2.2不空继续循环
3.循环中弹出队列头元素，判断是否有左右子树，有的话入队，没有继续跳到2

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
    public int[] levelOrder(TreeNode root) {
        if(root==null)return new int[0];
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        ArrayList<Integer> res=new ArrayList<>();
        while(!queue.isEmpty()){
            TreeNode node=queue.poll();
            res.add(node.val);
            if(node.left!=null)queue.add(node.left);
            if(node.right!=null)queue.add(node.right);
        }
        int[] result=new int[res.size()];
        for(int i=0;i<res.size();i++){
            result[i]=res.get(i);
        }
        return result;
    }
}
```