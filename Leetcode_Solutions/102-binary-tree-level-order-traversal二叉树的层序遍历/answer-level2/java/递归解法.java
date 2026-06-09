### 解题思路
此处撰写解题思路
感觉这题没什么人写递归的，我就献丑了，写的不好，麻烦留言一下~
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
    public List<List<Integer>> resultList=null;
    public List<List<Integer>> levelOrder(TreeNode root) {
        resultList=new ArrayList<List<Integer>>();
        helper(root,0);
        return resultList;
    }

    public void helper(TreeNode node ,int level){
        if(node==null) return;
        if(resultList.size()<=level){
            resultList.add(new ArrayList<Integer>());
        }
        resultList.get(level).add(node.val);
        helper(node.left,level+1);
        helper(node.right,level+1);
    }
}
```