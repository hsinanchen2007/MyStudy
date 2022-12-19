### 解题思路
双指针法
1 如果两个元素之和大于k，则表示两数之和sum太大，此时把较大的元素调小一点。继续循环
2 如果两个元素之和小于k，则表示两数之和sum太小，此时把较小的元素调小一点。继续循环
3 如果两数之和等于k，结束循环返回true。
   

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
    //双指针法
    List<Integer> list=new ArrayList<>();
    public boolean findTarget(TreeNode root, int k) {
            if(root==null) return false;    
            helper(root);
            int len=list.size()-1;
            int start=0;
            int end=len;
            while(start<end){
                int sum=list.get(start)+list.get(end);
                if(sum>k){//如果两个元素之和大于k，则表示两数之和sum太大，此时把较大的元素调小一点。
                    end--;
                }else if(sum<k){//如果两个元素之和小于k，则表示两数之和sum太小，此时把较小的元素调小一点
                    start++;
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