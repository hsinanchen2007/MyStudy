### 解题思路
[面试题32 - I. 从上到下打印二叉树](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/mian-shi-ti-32-i-cong-shang-dao-xia-da-yin-er-ch-8/)  的升级版



参考题解（感谢大佬）：
[面试题32 - II. 从上到下打印二叉树 II（队列 BFS，清晰图解）](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/mian-shi-ti-32-ii-cong-shang-dao-xia-da-yin-er-c-5/)
重点是以下这行代码，作为新手的我一下子还真写不出来 
`for(int i=deque.size();i>0;i--)`

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
        /*
        从上到下打印二叉树
        逐层打印
        */
     
        List<List<Integer> > list=new ArrayList<List<Integer> >();
        Deque<TreeNode> deque=new ArrayDeque<>();
        if(root!=null)
        {
            deque.add(root);
        }
   
        while(!deque.isEmpty()){
            List<Integer> tmp=new ArrayList<Integer>();
            for(int i=deque.size();i>0;i--){
                TreeNode node=deque.poll();
                tmp.add(node.val);
                if(node.left!=null){
                    deque.add(node.left);
                }
                if(node.right!=null){
                    deque.add(node.right);
                }
            }
            list.add(tmp);
        }
        return list;


    }
}
```