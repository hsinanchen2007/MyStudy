### 解题思路
利用中序遍历，搜索树的中序遍历就是顺序的。一定记住中序遍历的非递归写法。
思路：
1.不断往左子树深入并不断入栈直到左叶子的空左孩子
2.弹出栈顶，打印值，并将指针指向它的右孩子
3.循环1,2步骤直至栈为空且指针也为空
将打印值变成放入List中，然后List再进行连接指针。
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    public Node treeToDoublyList(Node root) {
        if(root==null) return null;
        Stack<Node> stack = new Stack<Node>();
        List<Node> list = new ArrayList<Node>();
        while (root!=null||!stack.isEmpty()){
            while (root!=null){
                stack.push(root);
                root = root.left;
            }
            if(!stack.isEmpty()){
                Node node = stack.pop();
                list.add(node);
                root=node.right;
            }
        }
       for(int i=0;i<list.size()-1;i++){
            list.get(i).right=list.get(i+1);
            list.get(i+1).left=list.get(i);
        }
       list.get(0).left=list.get(list.size()-1);
        list.get(list.size()-1).right=list.get(0);
        return list.get(0);
    }
}
```