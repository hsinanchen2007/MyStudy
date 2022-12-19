### 解题思路
收到《复杂链表复制》[面试题35. 复杂链表的复制](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/)一题的启发，使用一个hashmap 对树的节点进行排序记录（从1 开始）
**知识点一：在二叉搜索树中，节点的大小的排序和这棵树中序遍历的顺序一致
知识点二：树形结构是由链表衍化而来，所以树形结构可以用链表表示。**
拓展：其实本题还可以用List去解。（用链表去做，就要添加前驱指针pre）

HashMap<key,value> key:这个节点的val值在树中，排在第几位，从1开始排序
                value:存放节点
定义在代码中：HashMap<Integer,Node> memory = new HashMap<>();
通过memory 这一哈希表，我们得到数节点的一个从小到大的排序
遍历这个排序，将第j个Node 的left指针指向 j-1;
            将第j个Node 的right指针指向 j+1;
    当j=1的时候，当前节点的left指向尾结点
    当j=max 时，当前节点的right指向头结点。

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
     int i=1;
    HashMap<Integer,Node> memory = new HashMap<Integer,Node>();
    public Node treeToDoublyList(Node root) {
        if(root == null)
            return null;
        //中序遍历该二叉搜索树
        search(root,memory);
        i--;
        for(int j=1;j<=i;j++){
            // memory.get(j).left=null;
            // memory.get(j).right=null;
            if(j-1!=0){
                memory.get(j).left=memory.get(j-1);
            }else{
                memory.get(j).left=memory.get(i);
            }
            if(j+1>i){
                memory.get(j).right=memory.get(1);
            }else{
                memory.get(j).right=memory.get(j+1);
            }
        }
        return memory.get(1);
    }
    public void search(Node root,HashMap<Integer,Node> memory){
        if(root.left!=null){
            search(root.left,memory);
        }
        memory.put(i++,root);

        if(root.right!=null){
            search(root.right,memory);
        }
    }
}
```