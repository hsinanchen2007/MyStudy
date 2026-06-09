# 题目描述（中等难度）

![image.png](https://pic.leetcode-cn.com/dd752e8d0ee0bafd3d88ebd2f8ef5019915b39da1d99d838fb505c45fb8dd2dd-image.png)

二叉树的中序遍历。

# 解法一 递归

学二叉树的时候，必学的算法。用递归写简洁明了，就不多说了。

```java
public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    getAns(root, ans);
    return ans;
}

private void getAns(TreeNode node, List<Integer> ans) {
    if (node == null) {
        return;
    }
    getAns(node.left, ans); 
    ans.add(node.val);
    getAns(node.right, ans);
}
```

时间复杂度：O（n），遍历每个节点。

空间复杂度：O（h），压栈消耗，h 是二叉树的高度。

官方[解法]()中还提供了两种解法，这里总结下。

# 解法二 栈

利用栈，去模拟递归。递归压栈的过程，就是保存现场，就是保存当前的变量，而解法一中当前有用的变量就是 node，所以我们用栈把每次的 node 保存起来即可。

模拟下递归的过程，只考虑 node 的压栈。

```java
//当前节点为空，出栈
if (node == null) {
    return;
}
//当前节点不为空
getAns(node.left, ans);  //压栈
ans.add(node.val); //出栈后添加
getAns(node.right, ans); //压栈
//左右子树遍历完，出栈
```

看一个具体的例子，想象一下吧。

```java

        1
      /   \
     2     3
    / \   /
   4   5 6

 push   push   push   pop     pop    push     pop     pop 
|   |  |   |  |_4_|  |   |   |   |  |   |    |   |   |   |  
|   |  |_2_|  |_2_|  |_2_|   |   |  |_5_|    |   |   |   |
|_1_|  |_1_|  |_1_|  |_1_|   |_1_|  |_1_|    |_1_|   |   |
ans                  add 4   add 2           add 5   add 1
[]                   [4]     [4 2]           [4 2 5] [4 2 5 1]
 push   push   pop          pop 
|   |  |   |  |   |        |   |  
|   |  |_6_|  |   |        |   |  
|_3_|  |_3_|  |_3_|        |   |
              add 6        add 3
              [4 2 5 1 6]  [4 2 5 1 6 3]
```

结合代码。

```java
public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    Stack<TreeNode> stack = new Stack<>();
    TreeNode cur = root;
    while (cur != null || !stack.isEmpty()) {
        //节点不为空一直压栈
        while (cur != null) {
            stack.push(cur);
            cur = cur.left; //考虑左子树
        }
        //节点为空，就出栈
        cur = stack.pop();
        //当前值加入
        ans.add(cur.val);
        //考虑右子树
        cur = cur.right;
    }
    return ans;
}
```

时间复杂度：O（n）。

空间复杂度：O（h），栈消耗，h 是二叉树的高度。

# 解法三 Morris Traversal 

解法一和解法二本质上是一致的，都需要 O（h）的空间来保存上一层的信息。而我们注意到中序遍历，就是遍历完左子树，然后遍历根节点。如果我们把当前根节点存起来，然后遍历左子树，左子树遍历完以后回到当前根节点就可以了，怎么做到呢？

我们知道，左子树最后遍历的节点一定是一个叶子节点，它的左右孩子都是 null，我们把它右孩子指向当前根节点存起来，这样的话我们就不需要额外空间了。这样做，遍历完当前左子树，就可以回到根节点了。

当然如果当前根节点左子树为空，那么我们只需要保存根节点的值，然后考虑右子树即可。

所以总体思想就是：记当前遍历的节点为 cur。

1、cur.left 为 null，保存 cur 的值，更新 cur = cur.right

2、cur.left 不为 null，找到 cur.left 这颗子树最右边的节点记做 last

**2.1** last.right 为 null，那么将 last.right = cur，更新 cur = cur.left

**2.2** last.right 不为 null，说明之前已经访问过，第二次来到这里，表明当前子树遍历完成，保存 cur 的值，更新 cur = cur.right

结合图示：

![image.png](https://pic.leetcode-cn.com/7ca94efaf670f1b80fc04ce629ace14df9f9b270ea00608c0911603289d20f5f-image.png)

如上图，cur 指向根节点。 当前属于 2.1 的情况，cur.left 不为 null，cur 的左子树最右边的节点的右孩子为 null，那么我们把最右边的节点的右孩子指向 cur。

![image.png](https://pic.leetcode-cn.com/cac7d9152fb67492040a5e671e0c8028dfe7c19bd6d32073264ae8956b5df27d-image.png)

接着，更新 cur = cur.left。

![image.png](https://pic.leetcode-cn.com/04fa94380519ae48b05957a8e0ccdc14623e17654ce26b5f5b863e5f210012b1-image.png)

如上图，当前属于 2.1 的情况，cur.left 不为 null，cur 的左子树最右边的节点的右孩子为 null，那么我们把最右边的节点的右孩子指向 cur。

![image.png](https://pic.leetcode-cn.com/591cbd5a56d11926c06252e6b36b12eb7d3eabe18cf24a67be29103ddf40be99-image.png)

更新 cur = cur.left。

![image.png](https://pic.leetcode-cn.com/e217248e9dd34bec6b7a89c9b347b2244f3490f3d7f2d2dfa23c67bd96807538-image.png)

如上图，当前属于情况 1，cur.left 为 null，保存 cur 的值，更新 cur = cur.right。

![image.png](https://pic.leetcode-cn.com/867692a97fffe0e316c2358fdc0b179bb31e1bafff6223f2d5384b805848cb02-image.png)

如上图，当前属于 2.2 的情况，cur.left 不为 null，cur 的左子树最右边的节点的右孩子已经指向 cur，保存 cur 的值，更新 cur = cur.right。

![image.png](https://pic.leetcode-cn.com/95062e24a1dab55597b83377e40642ea3f523eb92f61871f356d46a2da76120e-image.png)

如上图，当前属于情况 1，cur.left 为 null，保存 cur 的值，更新 cur = cur.right。

![image.png](https://pic.leetcode-cn.com/16e840c6ce898b8dccdd8de155201c76a12cc903df5220b52c5f625a2b769624-image.png)

如上图，当前属于 2.2 的情况，cur.left 不为 null，cur 的左子树最右边的节点的右孩子已经指向 cur，保存 cur 的值，更新 cur = cur.right。

![image.png](https://pic.leetcode-cn.com/501d1242cb2f2ed81b0e3700bc9df886eb278f50d0e732aa7dfca443e818486a-image.png)

当前属于情况 1，cur.left 为 null，保存 cur 的值，更新 cur = cur.right。

![image.png](https://pic.leetcode-cn.com/122d127d371f31d3b2c71da3a540b40787bb7e16491039644c2d96c66e7afab9-image.png)

cur  指向 null，结束遍历。

根据这个关系，写代码

记当前遍历的节点为 cur。

1、cur.left 为 null，保存 cur 的值，更新 cur = cur.right

2、cur.left 不为 null，找到 cur.left 这颗子树最右边的节点记做 last

**2.1** last.right 为 null，那么将 last.right = cur，更新 cur = cur.left

**2.2** last.right 不为 null，说明之前已经访问过，第二次来到这里，表明当前子树遍历完成，保存 cur 的值，更新 cur = cur.right

```java
public List<Integer> inorderTraversal3(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    TreeNode cur = root;
    while (cur != null) {
        //情况 1
        if (cur.left == null) {
            ans.add(cur.val);
            cur = cur.right;
        } else {
            //找左子树最右边的节点
            TreeNode pre = cur.left;
            while (pre.right != null && pre.right != cur) {
                pre = pre.right;
            }
            //情况 2.1
            if (pre.right == null) {
                pre.right = cur;
                cur = cur.left;
            }
            //情况 2.2
            if (pre.right == cur) {
                pre.right = null; //这里可以恢复为 null
                ans.add(cur.val);
                cur = cur.right;
            }
        }
    }
    return ans;
}
```

时间复杂度：O（n）。每个节点遍历常数次。

空间复杂度：O（1）。

# 总

解法三是自己第一次见到，充分利用原来的空间的遍历，太强了。这么好的算法，当时上课的时候为什么没有讲，可惜了。

之前自己在博客总结的，更多题解可以在原地址 [https://leetcode.wang](https://leetcode.wang)。