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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(root,res,sum,new ArrayList<Integer>());
        return res;
    }

//回溯
    private void dfs(TreeNode root,List<List<Integer>> res,int target,List<Integer> list){
        if (root == null)
            return;
        if (root.left == null && root.right == null){
            if (target == root.val){
                list.add(root.val);
                List<Integer> temp = new ArrayList<>(list);
                res.add(temp);
                list.remove(list.size()-1);
                return;
            }
        }
        list.add(root.val);
        dfs(root.left,res,target-root.val,list);
        dfs(root.right,res,target-root.val,list);
        list.remove(list.size()-1);
    }
}
```

```java
class Solution {

//拷贝
    private void dfs(TreeNode root,List<List<Integer>> res,int target,List<Integer> list){
        List<Integer> list1 = new ArrayList<>(list);
        if (root == null)
            return;
        if (root.left == null && root.right == null){
            if (target == root.val){
                list1.add(root.val);
                List<Integer> temp = new ArrayList<>(list1);
                res.add(temp);
                return;
            }
        }
        list1.add(root.val);
        dfs(root.left,res,target-root.val,list1);
        dfs(root.right,res,target-root.val,list1);
    }
}
```