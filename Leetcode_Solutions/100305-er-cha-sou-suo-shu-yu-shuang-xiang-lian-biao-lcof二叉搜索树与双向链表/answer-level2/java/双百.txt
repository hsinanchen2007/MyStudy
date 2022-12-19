### 解题思路
详见注释
![image.png](https://pic.leetcode-cn.com/952030bcba226d6f832293f919874d0486c65d99560d6baf154819cc323db661-image.png)


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
        if(root == null){
            return null;
        }
        //获得第一个节点
        Node firstNode = getFirst(root);

        //获得最后一个节点
        Node lastNode = getLast(root);

        //dfs递归对每个节点做调整
        dfs(root);

        //处理首位节点
        firstNode.left = lastNode;
        lastNode.right = firstNode;

        //返回
        return firstNode;
    }

    public void dfs(Node node){
        //结束条件
        if(node == null){
            return;
        }

        //递归子树
        dfs(node.left);
        dfs(node.right);

        //处理本节点
        Node preNode = getLast(node.left);
        if(preNode != null){
            preNode.right = node;
            node.left = preNode;
        }

        Node aftNode = getFirst(node.right);
        if(aftNode != null){
            node.right = aftNode;
            aftNode.left = node;
        }
    }

    /*
    获取树的中序遍历的第一个元素
    */
    public Node getFirst(Node node){
        if(node == null){
            return null;
        }
        if(node.left == null){
            return node;
        }else{
            return getFirst(node.left);
        }
    }

    /*
    获取树的中序遍历的最后一个元素
    */
    public Node getLast(Node node){
        if(node == null){
            return null;
        }
        if(node.right == null){
            return node;
        }else{
            return getLast(node.right);
        }
    }
}
```