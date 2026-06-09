### 解题思路
此处撰写解题思路

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

一、递归
递归一定是先让pre的右节点指向当前，然后才让当前的left指向pre。
class Solution {
    Node pre,head;
    public Node treeToDoublyList(Node root) {
        //pre 记录当前节点的前一个节点，head记录头点解。
        if(root ==null){
            return null;
        }
        inorder(root);
        //当运行完中序遍历后，pre指的节点就是尾节点。然后连接头尾。
        head.left = pre;
        pre.right=  head;
        return head;
    }

    public void inorder(Node root){
        //递归出口
        if(root==null){
            return;
        }
        inorder(root.left);
        //这里pre会等于null，是因为找到了最左节点，他没有上一个节点，所以就是head
        //否则pre不为null时，就让pre的right指向当前节点
        if(pre==null){
            head = root;
        }else{
        //让前一节点的right指向当前，即使当前是个null(这种情况只有最右子节点)

            pre.right = root;
        }
        //无论如何让当前的left指向pre，即使pre是个null(这种情况只有最左子节点)
        root.left = pre;
        //更新pre指针，继续递归
        pre = root;
        inorder(root.right);
    }
}
```

二 非递归，栈
class Solution {
    Node pre,head,cur;
    public Node treeToDoublyList(Node root) {
        //pre 记录当前节点的前一个节点，head记录头点解。
        if(root ==null){
            return null;
        }
        cur = root;
        Stack<Node> stack = new Stack();
        //非递归是将节点一个一个放入栈中，如果有左子树，继续放，
        //没有的话就进行连接，然后进入右子树继续判断。
        //栈空了说明已有的节点已经处理完，cur不空代表当前还有节点未处理。
        while(!stack.isEmpty() || cur !=null){
            //有cur不为空说明有节点，就加入栈
            if(cur!=null){
                stack.push(cur);
                cur = cur.left;
            //否则说明这条路上已经没有节点，开始弹出并连接
            }else{
                cur = stack.pop();
                //判断是否是head
                if(pre==null){
                    head = cur;
                }else{
                    pre.right = cur;
                }
                cur.left = pre;
                pre = cur;
                cur = cur.right;
            }
        }
        //当运行完后，pre指的节点就是尾节点。然后连接头尾。
        head.left = pre;
        pre.right=  head;
        return head;
    }
}