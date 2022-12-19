### 解题思路
采用的是递归的方法做的，但是有好几种情况所以对于返回值不太好处理，这里采用的是将每次递归的计算结果保存在List中，然后再对List进行遍历，得出结果。

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
import java.util.ArrayList;
class Solution {
    private ArrayList<Integer> list=new ArrayList<>();
    public int maxPathSumSub(TreeNode root) {
        if (root==null) return 0;
        int left = maxPathSumSub(root.left);
        int right = maxPathSumSub(root.right);
        if (root.val>=0){
            list.add(Math.max(left+root.val+right,Math.max(left+root.val,Math.max(right+root.val,root.val))));
            return Math.max(left+root.val,Math.max(right+root.val,root.val));
        }
        else{
            if (left==0||right==0){
                if (left==0&&right==0){
                    list.add(root.val);
                    return root.val;
                }
                else if (left==0){
                    list.add(Math.max(root.val,root.val+right));
                    return Math.max(root.val,root.val+right);
                }
                else {
                    list.add(Math.max(root.val,root.val+left));
                    return Math.max(root.val,root.val+left);
                }
            }
            list.add(Math.max(left+root.val+right,Math.max(left+root.val,right+root.val)));
            return Math.max(left+root.val,right+root.val);
        }
    }
    public int maxPathSum(TreeNode root) {
        if(root==null) return 0;
        maxPathSumSub(root);
        int result=Integer.MIN_VALUE;
        for (int e:list) {
            result=result>e?result:e;
        }
        return result;
    }
}
```