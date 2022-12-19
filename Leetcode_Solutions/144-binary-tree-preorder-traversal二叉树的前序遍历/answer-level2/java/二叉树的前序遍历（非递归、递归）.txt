### 解题思路


### 代码

```java
/**递归**/
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        helper(root,list);
        return list;
    }

    private void helper(TreeNode p,List<Integer> li){
        if(p == null){
            return;
        }
        li.add(p.val);
        helper(p.left, li);
        helper(p.right,li);
        
    }
}
    
```


```java
/**迭代（用stack）**/
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        if(root == null) return list;
        
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode p = stack.pop();
            list.add(p.val);
            if(p.right != null){
                stack.push(p.right);
            }
            if(p.left != null){
                stack.push(p.left);
            }
        }
        return list;
        }
    }
```
    
