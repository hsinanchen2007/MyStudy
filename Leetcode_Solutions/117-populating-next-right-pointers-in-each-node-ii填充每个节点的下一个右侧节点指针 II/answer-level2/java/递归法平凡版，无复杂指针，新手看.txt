![image.png](https://pic.leetcode-cn.com/ee2c8ed2d8d53eb8ae6b66434c1ab931747aea536eee0b761b8b900c7fcecd43-image.png)

### 

核心是getNextNoNullChild，根据root，找到下一级右手第一个
然后分情况讨论，对每个节点：
左子右子都有，则左子next指向右子，右子next指向getNextNoNullChild
只有左子，左子指向getNextNoNullChild，
只有右子，右子指向getNextNoNullChild，

注意：递归时要先递归右子树，否则上级节点next关系没建好，下级无法成功getNextNoNullChild
### 代码

```java
// package com.leetcode.explore.learnCard.dataStructureBinaryTree.conclusion4;

/**
 * 补充节点的右侧指针，不是完美二叉树
 */
public class Solution {
    public Node connect(Node root) {
        if (root == null || (root.right == null && root.left == null)) {
            return root;
        }
        if (root.left != null && root.right != null) {
            root.left.next = root.right;
            root.right.next = getNextNoNullChild(root);
        }
        if (root.left == null) {
            root.right.next = getNextNoNullChild(root);
        }
        if (root.right == null) {
            root.left.next = getNextNoNullChild(root);
        }

        //这里要注意：先递归右子树，否则右子树根节点next关系没建立好，左子树到右子树子节点无法正确挂载
        root.right = connect(root.right);
        root.left = connect(root.left);

        return root;
    }

    /**
     * 一路向右找到有子节点的根节点
     */
    private static Node getNextNoNullChild(Node root) {
        while (root.next != null) {
            if (root.next.left != null) {
                return root.next.left;
            }
            if (root.next.right != null) {
                return root.next.right;
            }
            root = root.next;
        }
        return null;
    }
}

```