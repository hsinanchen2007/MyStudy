### 解题思路
![image.png](https://pic.leetcode-cn.com/53f8d803c10fd21cbab6fd5b0175f27e1a0c63ccf2e3fc926bb6dbfef5b2a795-image.png)

用一个指针记录当前结点的前驱，最后在把第一个结点的前驱指向最后一个结点，最后一个结点的后继指向第一个结点

### 代码

```java
class Solution {
    private Node head;
    private Node pre;
    public Node treeToDoublyList(Node root) {
        if(root==null) return null;
        dfs(root);
        //System.out.println(head==null);
        Node p=head;
        while(p.right!=null) {/*System.out.println(p.val);*/p=p.right;}
        head.left=p;
        p.right=head;
        return head;
    }
    private void dfs(Node root){
        if(root==null) return ;
        dfs(root.left);
        //if(pre!=null) System.out.println(pre.val+" "+root.val);
        if(pre==null) head=root;
        else{
            root.left=pre;
            pre.right=root;
        }
        pre=root;
        dfs(root.right);
    }
}
```