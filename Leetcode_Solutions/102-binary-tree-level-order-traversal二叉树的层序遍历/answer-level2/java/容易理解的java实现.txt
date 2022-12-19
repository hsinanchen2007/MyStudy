### 解题思路
层次遍历首先想到的就是队列实现，要将每一层的节点存入一个链表，就要知道每层的节点个数。
开始根节点从队尾入队列，此后每从队列中取出一个节点，判断该节点有没有左子树或右子树，有的话记录下一层节点数的nextNodeCount就要+1，当前层剩余需要遍历的节点数就-1。

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
        if(root == null)
            return list;
        //使用队列存储节点
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        //记录当前层需要遍历的节点数与下一层的节点数
        int nodeCount = 1,nextNodeCount=0;
        //对根节点的处理
        List<Integer> inlist;
        que.offer(root);

        while(que.size() != 0){
            //每层节点新建list
            inlist = new ArrayList<Integer>();
            while(nodeCount != 0){
                TreeNode nowRoot = que.poll(); //取出队头的元素，并删除，为空时返回null
                inlist.add(nowRoot.val);  //存到链表中
                if(nowRoot.left != null){
                    que.offer(nowRoot.left);
                    nextNodeCount++;
                }
                if(nowRoot.right != null){
                    que.offer(nowRoot.right);
                    nextNodeCount++;
                }
                nodeCount--;
            }
            list.add(inlist);
            nodeCount = nextNodeCount;
            nextNodeCount = 0;   
        }
        return list;
    }
}
```