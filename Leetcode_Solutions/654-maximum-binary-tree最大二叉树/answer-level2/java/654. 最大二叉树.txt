### 654. 最大二叉树
- 执行用时 : 2 ms, 在所有 java 提交中击败了99.89%的用户
- 内存消耗 : 37.8 MB, 在所有 java 提交中击败了94.24%的用户


#### **思路：**
- 设数组起始下标为start，数组结束下标为end，start与end之间的数组段中最大值（maxValue）的下标设为maxValueIndex。

- 若将下标为start到end之间的数组段建立成最大二叉树，需要：
1. 递归终止条件：start>end，返回空节点
2. 将下标为maxValueIndex的元素设为根节点root
3. 建立root的左子树，即，将下标为start至maxValueIndex-1的数组段建立成最大二叉树
4. 建立root的右子树，即，将下标为maxValueIndex+1至end的数组段建立成最大二叉树

#### **代码：**
```
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if(nums==null||nums.length==0){
            return null;
        }
        return constructMaximumBinaryTree(nums,0,nums.length-1);
    }
    public TreeNode constructMaximumBinaryTree(int[]nums,int start,int end){
        if(start>end){
            return null;
        }
        int maxValueIndex=findMaxValueIndex(nums,start,end);
        TreeNode root=new TreeNode(nums[maxValueIndex]);
        root.left=constructMaximumBinaryTree(nums,start,maxValueIndex-1);
        root.right=constructMaximumBinaryTree(nums,maxValueIndex+1,end);
        return root;
    }
    public int findMaxValueIndex(int[] nums,int start,int end){  //此函数用于找出数组中最大值的下标
        int maxValue=Integer.MIN_VALUE;
        int maxValueIndex=start;
        for(int i=start;i<=end;++i){
            if(nums[i]>maxValue){
                maxValue=nums[i];
                maxValueIndex=i;
            }
        }
        return maxValueIndex;
    }
}
```
