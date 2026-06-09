### 解题思路
https://www.zhihu.com/people/god-jiang

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
    List<List<Integer>> result=new ArrayList<>();
    List<Integer> list=new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root==null){
            return result;
        }
        list.add(root.val);
        sum-=root.val;
        if(sum==0&&root.left==null&&root.right==null){
            result.add(new ArrayList<Integer>(list));
        }
        pathSum(root.left,sum);
        pathSum(root.right,sum);
        list.remove(list.size()-1);
        return result;
    }
}
```