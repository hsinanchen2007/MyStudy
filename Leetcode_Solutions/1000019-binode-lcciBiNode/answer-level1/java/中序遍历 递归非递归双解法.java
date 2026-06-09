### 解题思路
递归和非递归两种思路

1.非递归，BST中序遍历是有序的，我们只要对树进行中序遍历即可，利用一个前驱节点prev，记录上一个被处理的节点，当前节点被遍历到的时候，将prev.right指向当前节点node，然后node.left置空，prev指针后移到node,最后node进入右子树即可。

2.递归，思路基本与非递归相同，不过要注意的是递归之后的prev指针要返回，因为JAVA中是没有引用传递的，左子树递归回来之后，当前的prev指针没有发生改变，还是外部传进来的那个哨兵节点，这个时候一旦进入右子树，之前的prev.right指针将会被重置。也就是说，root的左子树操作全部失效了。

### 核心代码
```
node.left = null;// 当前节点左指针置空
prev.right = node;// 前置指针右指针指向当前节点，作为链表的next指针，链表新增元素
prev = node;// 指针后移
```

递归的效率会比非递归要高一些，递归用时1ms，用栈的非递归6-7ms的样子

### 非递归代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode convertBiNode(TreeNode root) {
        TreeNode head = new TreeNode(0);// 单链表的头指针哨兵
        TreeNode prev = head;// 移动的链表前置指针
        // 开始中序遍历
        TreeNode node = root;
        Deque<TreeNode> stack = new LinkedList<>();
        while (node != null || !stack.isEmpty()){
            if (node != null){
                stack.push(node);
                node = node.left;
            }else {
                node = stack.pop();
                // ---链表处理
                node.left = null;// 当前节点左指针置空
                prev.right = node;// 前置指针右指针指向当前节点，作为链表的next指针，链表新增元素
                prev = node;// 指针后移
                // ---链表处理
                // 中序遍历进入右子树
                node = node.right;
            }
        }
        return head.right;
    }
}
```

### 递归代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode convertBiNode(TreeNode root) {
        TreeNode head = new TreeNode(0);// 单链表的头指针哨兵
        // 开始中序遍历
        inorder(root,head);
        return head.right;
    }

    private TreeNode inorder(TreeNode root,TreeNode prev){
        if (root != null){
            prev = inorder(root.left,prev);
            root.left = null;
            prev.right = root;
            prev = root;
            prev = inorder(root.right,prev);
        }
        return prev;
    }
}
```