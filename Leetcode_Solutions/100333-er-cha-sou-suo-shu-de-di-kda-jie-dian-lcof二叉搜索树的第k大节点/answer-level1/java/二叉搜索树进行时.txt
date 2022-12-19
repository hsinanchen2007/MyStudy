### 解题思路
此处撰写解题思路
一： 搜索二叉树有着很好的性质，从左子树开始则搜索到的是从小到大的第k个最小的数；从右子树开始则搜索到的是从大到小第k大的数字
二： 首先需要遍历到最右的叶子节点，相当于从右节点开始的中序遍历；题目所给函数不能方便地完成递归，有int返回值，实际上需要的是此时是哪个节点，因此新建一个void函数，为了知道是第k个最大的以及第k个最大的值
需要两个全局变量
三：递归出口，如果root==nul则跳出
四：递归操作，遍历root.right，如果count==1说明此时的root就是第一个大的，count--,如果不进行这和操作返回root后会再次进入count==1这个判断，不是，则count--，遍历root.left
五：count < 1,是后面加上去的，相当于一个减枝操作

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
    
    int count;
    int result = -1;

    public int kthLargest(TreeNode root, int k) {
        count = k;
        kthLargest(root);
        return result;
    }

    public void kthLargest(TreeNode root) {
        if(root == null || count < 1)
            return;
        kthLargest(root.right);
        if(count == 1){
            result = root.val;
            count--;
            return;
        }
        count--;
        kthLargest(root.left);
    }
}
```