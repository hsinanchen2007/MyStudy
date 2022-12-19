### 解题思路

关注好当前节点就好，不要钻牛角尖，下一层的事情，迭代过去了，自然就会做的，计算机擅长的就是重复的事情。

之前已经看到有蛮多大佬已经写了前中后序的递归解法了，我这边就写一个非递归的代码，给大家参考了。

核心代码
```
TreeNode temp = node.left;
node.left = node.right;
node.right = temp;
```


### 前序遍历非递归

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
    public TreeNode mirrorTree(TreeNode root) {
        if (root == null){
            return null;
        }
        TreeNode node = root;
        Deque<TreeNode> stack = new LinkedList<>();
        while (node != null || !stack.isEmpty()){
            if (node != null){
                // 交换左右子树
                inventTreeNode(node);
                // 原先的先序遍历
                stack.push(node);
                node = node.left;
            }else {
                node = stack.pop();
                node = node.right;
            }
        }
        return root;
    }
    
    private void inventTreeNode(TreeNode node){
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
```

### 中序遍历非递归

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
    public TreeNode mirrorTree(TreeNode root) {
        if (root == null){
            return null;
        }
        TreeNode node = root;
        Deque<TreeNode> stack = new LinkedList<>();
        while (node != null || !stack.isEmpty()){
            if (node != null){
                stack.push(node);
                node = node.left;
            }else {
                node = stack.pop();
                // 交换左右子树
                inventTreeNode(node);
                // 这里因为交换了，不能继续往右子树走，因为现在的右子树，是原来的左子树
                // 所以接下来要走左边
                node = node.left;
            }
        }
        return root;
    }
    
    private void inventTreeNode(TreeNode node){
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
```

### 后序遍历非递归

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
    public TreeNode mirrorTree(TreeNode root) {
        if (root == null){
            return null;
        }
        TreeNode node = root;
        TreeNode tempNode = null;// 记录上次访问的节点
        Deque<TreeNode> stack = new LinkedList<>();
        while (node != null || !stack.isEmpty()){
            if (node != null){
                stack.push(node);
                node = node.left;
            } else {
                node = stack.peek();
                if (node.right == null || node.right == tempNode){
                    // 右节点为空，或者右节点已经被访问过
                    // 当前节点出栈
                    tempNode = stack.pop();
                    // 交换
                    inventTreeNode(node);
                    // 这里要置空，不然node还是存在，又会往左子树去了
                    node = null;
                }else {
                    node = node.right;
                }
            }
        }
        return root;
    }
    
    private void inventTreeNode(TreeNode node){
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
```

### 层次遍历

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
    public TreeNode mirrorTree(TreeNode root) {
        if(root == null){
            return null;
        }
        TreeNode node = root;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(node);
        while(!queue.isEmpty()){
            node = queue.poll();
            // 翻转左右子树
            inventTreeNode(node);
            if(node.left != null){
                queue.offer(node.left);
            }
            if(node.right != null){
                queue.offer(node.right);
            }
        }
        return root;
    }
    
    private void inventTreeNode(TreeNode node){
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
```