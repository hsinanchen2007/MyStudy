1. 递归中序遍历 

设置一个全局变量prev记录当前指针的前一位 还需要一个虚拟头节点dummy 让prev = dummy

每次递归时，让prev.right = curr  curr.left = prev prev=prev.right，使得prev和curr 左右相连 且prev不断后移 直至最后一位

递归结束后 此时prev指的链表最后一位 dummy.right为链表第一位 然后让prev = dummy.right dummy.right.left = prev
```
class Solution {

    Node prev = null;
    public Node treeToDoublyList(Node root) {
        if(root == null)
            return null;
        Node dummy = new Node(0,null,null);
        prev = dummy;
        
        helper(root);
        
        prev.right = dummy.right;
        dummy.right.left = prev;
        
        return dummy.right;
    }
    
    public void helper(Node curr)
    {
        if(curr == null)
            return;
        helper(curr.left);
        
        curr.left = prev;
        prev.right = curr;
        prev = curr;
        
        helper(curr.right);
    }
}
```

2. 迭代中序遍历 

设置一个变量pre设置为当前指针的前一位

与递归一样，每次循环时，让prev.right = root root.left = prev prev=prev.right，使得prev和root 左右相连 且prev不断后移 直至最后一位

迭代结束后 与递归一样 此时prev指的链表最后一位 res.right为链表第一位 然后让prev = res.right res.right.left = prev
```

class Solution {
    public Node treeToDoublyList(Node root) {
        if(root == null)
            return root;
        
        Stack<Node> stack = new Stack<>();
        Node pre = new Node(0,null,null);
        Node res = pre;
        
        while(root != null || !stack.isEmpty())
        {
            if(root != null)
            {
                stack.push(root);
                root = root.left;
            }
            else
            {
                root = stack.pop();
                pre.right = root;
                root.left = pre;
                pre = root;
                root = root.right;
            }
        }
        pre.right = res.right;
        res.right.left = pre;
        
        return res.right;
        
    }
}
```