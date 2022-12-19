### 思路
二叉搜索树BST(Binary Search Tree):任意一节点的值，大于等于左子树的值，小于等于右子树的值。
根据这个定义：我们设计递归！
由于该数组是有序的，我们可以将数组分成两部分
![image.png](https://pic.leetcode-cn.com/da895c4b921e4437251f9fcfe7053bc7069fca230e4ee52278ccdc3f0c8b2baa-image.png)
中值作为父节点（node）	int mid = left + (right-left）/2  
小于部分作为左子树 (node.left) 
大于部分作为右子树(node.right)

让左子树成为二叉搜索树，让右子树成为二叉搜索树！最终整个树是二叉搜索树！
运行结果图为：
![image.png](https://pic.leetcode-cn.com/7b5c3e75290fbd632982d8f7987567febc63926a30f268ba5e6c7eed32afac1b-image.png)

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
    public TreeNode sortedArrayToBST(int[] nums) {
        return core(nums,0,nums.length-1,null);
    }
    public TreeNode core(int[] num, int left, int right, TreeNode root){
        if ( left>right )
            return null;
        int mid = left+(right-left)/2;
        root = new TreeNode(num[mid]);

        root.left = core(num, left, mid-1, root.left);
        root.right = core(num, mid+1, right, root.right);
        return root;
    }
}
```