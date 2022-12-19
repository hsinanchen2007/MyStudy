
广度优先遍历，关键点  
1.创建层次数组的时机
2.传递层次进去是很美妙的实现

Java
```java
class Solution {
    private List<List<Integer>> levels;
    public Solution() {
        this.levels = new ArrayList<>();
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(Objects.isNull(root)) {
            return levels;
        }
         bfsBinaryTree(root,0);
        return levels;
    }
  
    private void bfsBinaryTree(TreeNode node,int level) {
        if(Objects.isNull(node)) {
            return;
        }
        
        if(levels.size() == level) {
            levels.add(new ArrayList<>());
        }
        levels.get(level).add(node.val);
        
        bfsBinaryTree(node.left,level+1);
        bfsBinaryTree(node.right,level+1);
    }    
}
```
