## 解题思路
### 递归写法
1. 遍历时从顶点开始，每层都建立一个新的子数组，用于存放顶点的值
2. 将左二子和右儿子的值加入到数组中
3. 将层级++，递归到子树去执行，同时携带全局数组，逐层给level对应的数组中添加新值
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (root == null) return list;
        addObj(list, 0,root);
        System.out.println(list);
        return list;
    }
    public void addObj(List<List<Integer>> levels,int level,TreeNode node){
        if (levels.size() == level)
            levels.add(new ArrayList<Integer>());

        List<Integer> temp = levels.get(level);
        int a = node.val;
        temp.add(a);

        if (node.left != null) {
            addObj(levels, level+1, node.left);
        };
        if ( node.right != null) {
            addObj(levels, level+1, node.right);
        }
    }
}
```