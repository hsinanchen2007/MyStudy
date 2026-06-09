### 解题思路  1.要找到递归终止条件，遇到空节点结束
            2.利用数组存放路径，然后以最后一个点依次向前加，计算总和为sum的路径和。
            3.返回值为，当前cur+下一个左子树或右子树的路径数。


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
    public int pathSum(TreeNode root, int sum) {
        if(root==null) return 0;
        return getSum(root,sum,new int[1000],0);

    }
    public int getSum(TreeNode root,int sum,int[] Array,int layer){
        if(root==null) return 0;
        Array[layer]=root.val;
        int temp=0,cur=0;
        for(int i=layer;i>=0;i--){
            temp+=Array[i];
            if(temp==sum) cur++;
        }
        return cur+getSum(root.left,sum,Array,layer+1)+getSum(root.right,sum,Array,layer+1);
    }
}
```