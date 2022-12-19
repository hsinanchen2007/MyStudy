### 解题思路
题目分析：根据二叉搜索树的特点得知，要得到一个有序的双向链表，就需要用中序遍历树。然后存入链表同时规定指针的方向即可。
既然链表是有序的，那么就根据中序遍历得到最小的值开始存入链表。因此可以利用递归-深度优先遍历（DFS）。

**步骤**
1. 创建指针head指向伪头节点pre，作为初始化
2. 编写DFS方法遍历树，其中先找到最小的叶子节点，修改指针[pre.right = cur;  cur.left = pre;//双向指针  pre = cur;//向右移动]，返回上一层递归，最后遍历当前节点的右子树。重复此操作，即可得到一个双向链表
3. 再次修改头指针head和尾指针pre，使其成为双向链表
4. 返回头指针head

**说明**
时间复杂度：O(N)  N为节点数，需要遍历全部节点
空间复杂度：O(N)  每个节点都需要空间
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
    Node pre = new Node(0);
    Node head = pre;
    public Node treeToDoublyList(Node root) {
        if(root == null) return root;
        DFS(root);
        head = head.right;
        head.left = pre;
        pre.right = head;
        return head;

    }

    public void DFS(Node cur){
        if(cur == null) return;
        DFS(cur.left);
        pre.right = cur;
        cur.left = pre;
        pre = cur;
        DFS(cur.right);
    }
}
```