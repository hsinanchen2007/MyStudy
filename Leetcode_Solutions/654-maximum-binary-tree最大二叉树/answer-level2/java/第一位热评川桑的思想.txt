### 解题思路
此处撰写解题思路

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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return constructTree(nums,0,nums.length-1);

    }
    //三部曲代码
    //终止条件-一次递归要做什么-返回值
    public TreeNode constructTree(int[] nums,int left ,int right){
        //第一步 也是终止条件
        if(left > right){
            return null;
        }

        //开始编写第二步
        //要找到最大值，和索引
        int nowMax = fineIndex(nums,left,right);
        //根节点，也就是每次要做的，这一层递归要做的
        TreeNode root = new TreeNode(nums[nowMax]); 
        root.left = constructTree(nums,left,nowMax-1);
        root.right = constructTree(nums,nowMax+1,right);
        //最后是返回值，我认为的三部曲的最后一部
        return root;
    }



    //每次都要找到最大值的索引，因为这里都是根据索引来判断大小
    public int fineIndex(int[] nums,int left,int right){
        int max = Integer.MIN_VALUE, index = left;
        // 这里需要注意遍历完
        
        for(int i =  left;i <=right;i++){
            if(max < nums[i]){
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
}
```