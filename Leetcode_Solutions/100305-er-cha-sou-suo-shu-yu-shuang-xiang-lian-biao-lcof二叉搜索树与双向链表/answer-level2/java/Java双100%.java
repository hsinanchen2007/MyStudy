思路：

arr[0]保存中序前驱，arr[1]保存中序第一次访问的节点，中序遍历时构造链表


代码：

```
class Solution {
     public Node treeToDoublyList(Node root) {
         if(root==null)return null;
        Node[] arr=new Node[2];
        
        helper(root,arr);
        arr[0].right=arr[1];
        arr[1].left=arr[0];
        return arr[1];
    }

    private void helper(Node root,Node[] arr) {
        if (root==null)return;
        helper(root.left,arr);
        if (arr[0]==null)
            arr[1]=root;
        else 
        {
            root.left=arr[0];
            arr[0].right=root;
        }
        arr[0]=root;
        helper(root.right,arr);
    }
}
```





