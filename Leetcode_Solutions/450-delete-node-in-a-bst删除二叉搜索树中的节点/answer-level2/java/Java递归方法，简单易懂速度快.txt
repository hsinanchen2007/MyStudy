> **执行结果：** 通过 
>
> **执行用时 :** **1 ms**, 在所有 Java 提交中击败了 **97.47%** 的用户
>
> **内存消耗 :** **45.4 MB**, 在所有 Java 提交中击败了 **73.60%** 的用户

[TOC]

## 明确递归函数的意义

明确函数的意义：deleteNode(root, key)，**返回删除指定节点后的树的根节点**。

对于给定的key，分三种情况：

## 1. key < root.val

此时需要到root的左子树中去删除节点，然后让root.left指向左子树删除节点后的根节点：

```java
if (key < root.val) {
    root.left = deleteNode(root.left, key);
    return root;
}
```

## 2. key > root.val

此时需要到root的右子树中去删除节点，然后让root.right指向右子树删除节点后的根节点：

```java
if (key > root.val) {
    root.right = deleteNode(root.right, key);
    return root;
}
```

## 3. key = root.val

此时当前节点即为要删除的节点，此时，还要分三种情况：

### 3.1 root.left == null，直接返回root.right即可

```java
if (root.left == null) {
    TreeNode rightNode = root.right;
    root.right = null;
    return rightNode;
}
```

### 3.2 root.right == null，直接返回root.left即可

```java
if (root.right == null) {
    TreeNode leftNode = root.left;
    root.left = null;
    return leftNode;
}
```

### 3.3 root的左右子树都不为空的情况

我们使用右子树的最小的节点，代替当前要被删除的节点，再在右子树中删除该最小节点即可。

因此我们还需要两个函数：

* `public TreeNode minmum(TreeNode node)`：返回以node为跟的最小的节点

```java
public TreeNode minmum(TreeNode node) {      
    if (node.left == null)
        return node;

    return minmum(node.left);
}
```

* `public TreeNode removeMin(TreeNode node)`：删除以node为跟的树中的最小节点，并返回删除后的树根节点：

```java
public TreeNode removeMin(TreeNode node) {    
    if (node.left == null) {
        TreeNode rightNode = node.right;
        node.right = null;
        return rightNode;
    }

    node.left = removeMin(node.left);

    return node;
}
```

所以针对左右子树都不为空的情况：

```java
// 找到右子树的最小节点
TreeNode successor = minmum(root.right);
// 使用该最小节点代替要删除的节点，即：
// 1. 该节点的右子树为root的右子树删除该最小节点
// 2. 该节点的左子树为原来节点的左子树
// 3. 断开原来节点的左右子树
successor.right = removeMin(root.right);
successor.left = root.left;
root.left = root.right = null;

return successor;
```

## 4. 完整代码

```java
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null)
            return null;
        
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        else if (key > root.val) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        else {
            if (root.left == null) {
                TreeNode rightNode = root.right;
                root.right = null;
                return rightNode;
            }
            
            if (root.right == null) {
                TreeNode leftNode = root.left;
                root.left = null;
                return leftNode;
            }
            
            TreeNode successor = minmum(root.right);
            successor.right = removeMin(root.right);
            successor.left = root.left;
            root.left = root.right = null;
            
            return successor;
        }
    }
    
    public TreeNode removeMin(TreeNode node) {    
        if (node.left == null) {
            TreeNode rightNode = node.right;
            node.right = null;
            return rightNode;
        }
        
        node.left = removeMin(node.left);
        
        return node;
    }
    
    public TreeNode minmum(TreeNode node) {      
        if (node.left == null)
            return node;
        
        return minmum(node.left);
    }
    
}
```

