### 解题思路
1 把中序遍历的结果放在list集合中
2 用两个指针遍历集合
3 遍历到的两个元素相加看是否等于k。

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
    List<Integer> list=new ArrayList<>();
    public boolean findTarget(TreeNode root, int k) {
            helper(root);
            int len=list.size();
            int left=0;
            if(len<=0) return false;
            int right=len-1;
            while(left<right){
                int sum=list.get(left)+list.get(right);
                if(sum<k){
                    left++;
                }else if(sum>k){
                    right--;
                }else{
                    return true;
                }
            }
            return false;
}
public void helper(TreeNode root){
    if(root==null) return ;
    helper(root.left);
    list.add(root.val);
    helper(root.right);
}
}
```