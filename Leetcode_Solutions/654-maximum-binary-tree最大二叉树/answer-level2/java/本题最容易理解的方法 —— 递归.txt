### 解题思路
这一题很容易想到的方法就是递归法，很多人觉得递归法很难理解，我最初接触的时候也是一样，看了很多文章和视频，现在我对递归法有了初步的理解和运用。对于递归法，我觉得掌握以下两个关键即可：
1、整体思维
2、结束条件
针对本题，我们需要给出“求二叉树根节点的方法” —— constructMaximumBinaryTree()， 我们需要知道，这个方法的功能为：返回二叉树根节点。有了这个思维，本题的递归解法你已经掌握了一半。那么结束条件是啥呢？先不用着急找，开始解题。
我的思路如下：
1、先遍历整个数组，找到最大的那个数，记下来它的索引和值，以下记为“索引”和“值”。
2、给根节点赋值，根节点的val就是“值”，比较简单。复杂一点的是求它的左右子树。
3、它的左子树怎么求呢？左子树就是constructMaximumBinaryTree(“索引”左边的数组);还记得这个方法的作用是什么吗？求出二叉树的根节点。同理，右子树也是一样的方法。
4、最后来看它的结束条件。如果 constructMaximumBinaryTree() 这个方法的入参数组的长度只有 1，那么它肯定就是叶子节点，是没有左右子树的。则直接给它的val赋值即可，不用给它的左右子树赋值，那么就是返回 return new TreeNode(nums[0]) 即可。这就是它的结束条件。
代码如下，此题还有优化效率的方法，比如说获取数组最大值的方法便可优化，读者可自行想。
###  最后打一波公益广告：欢迎大家加入 leetcode 刷题群：QQ：940835717（升值加薪冲冲冲），互相监督学习，共同成长，欢迎志同道合之士加入。

### 代码

```java
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
    public void setLeft(TreeNode left) {
        this.left = left;
    }

    public void setRight(TreeNode right) {
        this.right = right;
    }
 }
 
public class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if (nums.length == 1) {
            return new TreeNode(nums[0]);
        }
        int[] maxNumIndex = getMaxNum(nums);
        TreeNode treeNode = new TreeNode(maxNumIndex[1]);
        int index = maxNumIndex[0];
        int[] leftNums = new int[index];
        System.arraycopy(nums, 0, leftNums, 0, leftNums.length);
        int[] rightNums = new int[nums.length - index - 1];
        System.arraycopy(nums, index + 1, rightNums, 0, rightNums.length);
        if (leftNums.length > 0) {
            treeNode.setLeft(constructMaximumBinaryTree(leftNums));
        }
        if (rightNums.length > 0) {
            treeNode.setRight(constructMaximumBinaryTree(rightNums));
        }
        return treeNode;
    }

    private int[] getMaxNum(int[] nums) {
        int max = nums[0];
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }
        int[] result = new int[2];
        result[0] = index;
        result[1] = max;
        return result;
    }
}
```