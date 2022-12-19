### 解题思路

https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/li-yong-zhan-lai-qian-xu-fang-wen-by-hongan/
都是前序遍历，这篇与链接中这上篇还是有区别。
上篇，按照节点上下级关系进行压栈。
>同一个节点在回溯时会再次被加入，所以要区分，防止重复。
本篇，只对新节点进行压栈。
>更为清晰。

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
    public int kthSmallest(TreeNode root, int k) {
        if(root ==null || k<1){
            throw new IllegalArgumentException();
        }

        TreeNode node = root;
        LinkedList<TreeNode> nodeStack = new LinkedList<TreeNode>();
        while(node!=null || !nodeStack.isEmpty()){
            while(node!=null){
                nodeStack.addLast(node);
                //System.out.println(String.format("->%d",node.val));//
                node = node.left;
            }
            node = nodeStack.pollLast();
            //System.out.println(String.format("<-%d",node.val));//
            //System.out.println(String.format("~~%d",node.val));//
            //System.out.println(String.format("k%d",k));//
            if(--k==0){
                return node.val;
            }
            node = node.right;
        }
        if(k!=0){
            throw new IllegalArgumentException();
        }
        return Integer.MIN_VALUE;
    }
}
```