### 解题思路
题解特点--作者初学编程，所用解法为最小白解法
本题知识点有以下两点：
1.设置*level*参数，这个参数最根本的作用在于定位*ans*集合中的一个*ArrayList*集合来添加待添加元素，次要作用为当进入新的一层时，创建新的*ArrayList*并将这个集合添加到*ans*集合中。
2.利用*for*循环来遍历子节点集合*children*，再利用递归就可以完成该题。

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> levelOrder(Node root) {
        if(root==null) return ans;
        helper(root,0);
        return ans;
    }
    public void helper(Node root,int level){
        if(ans.size()==level){
            ans.add(new ArrayList<>());
        }
        ans.get(level).add(root.val);
        if(root.children!=null){
            for(int i=0;i<root.children.size();i++){
                helper(root.children.get(i),level+1);
            }
        }
    }
}
```