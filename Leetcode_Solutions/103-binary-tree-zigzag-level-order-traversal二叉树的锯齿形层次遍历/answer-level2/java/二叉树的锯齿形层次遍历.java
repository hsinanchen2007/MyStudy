## 循环迭代
栈思想：锯齿状，应为栈的使用场景，用栈保存遍历的路径。
```java
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);
        boolean leftToRight = true;
        while(!stack.isEmpty()){
            List<Integer> list = new LinkedList<>();
            Stack<TreeNode> level = new Stack<>();
            while(!stack.isEmpty()){
                     TreeNode node =stack.pop();
                     if(node==null) continue;
                    list.add(node.val);   
                    if(leftToRight){
                        level.add(node.left);
                        level.add(node.right);  
                    }else{
                        level.add(node.right);
                        level.add(node.left);  
                    }
            }
            if(list.size()==0) return result;
            result.add(list);
            stack.addAll(level);
            leftToRight=!leftToRight;
        }
        return result;
    }
}
```