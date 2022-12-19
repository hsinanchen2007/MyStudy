### 解题思路
1.先使用递归遍历把元素添加到一个数组中
2.遍历数组,满足条件的加到一起.

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

 //递归 + 前序遍历
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
       List<Integer> result =  kk(root);
       int count = 0;
       for(Integer val:result){
           if(val >=L && val <= R){
                count += val;
           }
       }
       return count;
    }

    public List<Integer> kk(TreeNode root){
        List<Integer> list = new ArrayList<Integer>();
        if(root == null) return list;
        List<Integer> listA =  kk(root.left);
        for(Integer val:listA){
            list.add(val);
        }
        list.add(root.val);
       List<Integer> listB = kk(root.right);
        for(Integer val:listB){
            list.add(val);
        }
        return list;
    }
}
```