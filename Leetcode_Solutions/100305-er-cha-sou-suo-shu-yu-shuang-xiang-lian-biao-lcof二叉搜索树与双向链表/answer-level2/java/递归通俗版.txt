如果按照中序遍历的顺序来执行的话，那么链表的顺序是确定下来的，我们需要做的就是根据这个顺序确定双向链表的连接，对于一个节点，应该改变的双向链表的连接有两种，pre->cur和 cur->pre（中序遍历左边的已经遍历过，可以修改，但右边的还没遍历，修改的话中序的顺序就不对了）

那么执行部分就是就是这两个语句
cur.left=pre
pre.right=root

然后修改pre  pre=cur；

```
class Solution {
        Node pre,head;
        public Node treeToDoublyList(Node root) {
            if(root == null) return null;

            inorder(root);

            while(root.right!=null){//这4行连一下head和tail
                root=root.right;
            }
            root.right=head;
            head.left=root;

            return head;
        }
        private void inorder(Node cur){
            if(cur==null)return;
            inorder(cur.left);

            if(pre==null) head=cur;//修改、更新
            else pre.right=cur;
            cur.left=pre;
            pre=cur;

            inorder(cur.right);
            return;
        }
    }
```
