执行用时 :2 ms, 在所有 Java 提交中击败了90.49% 的用户
内存消耗 :37.4 MB, 在所有 Java 提交中击败了34.18%的用户

写一个函数用于先序遍历二叉树：先判断结点是否非空，非空的话判断总的levelList是否存在当前层级的valList元素，如果不存在，新建valList用来存放当前层的结点值，再将这个valList存放在levelList中；如果存在，直接将当前节点的值存入对应valList中就可以了。然后进行递归遍历。
代码：
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levelList = new ArrayList<List<Integer>>();
        func(root,0,levelList);
        return levelList;
    }
    public void func(TreeNode node, int level, List<List<Integer>> levelList){
        if(node==null){
            return;
        }
        if(levelList.size()<=level){
            List<Integer> valList = new ArrayList<>();
            valList.add(node.val);
            levelList.add(valList);
        }else{
            levelList.get(level).add(node.val);
        }
        func(node.left,level+1, levelList);
        func(node.right,level+1, levelList);
    }
}
```
