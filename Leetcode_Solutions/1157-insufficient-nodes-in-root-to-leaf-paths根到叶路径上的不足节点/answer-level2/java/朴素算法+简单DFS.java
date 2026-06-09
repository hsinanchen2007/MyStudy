# **方法一**
从题目描述来看，很容易想到最简单的办法，对于每个结点node，计算经过该结点的每条“根-叶”路径上的结点值之和，然后判断是不是每条路径的和都小于limit，全部小于limit则为不足结点，需要删除，否则保留。
![7d5d1266dcc985082043_1078x611.png](https://pic.leetcode-cn.com/4896359f7ff5befc4df075452a5c41167d447b37b50032709482b806c5ae9a67-7d5d1266dcc985082043_1078x611.png)

如图所示，图中对于每个结点都标出了经过该结点的每条“根-叶”路径上的结点值之和，其中绿色的是保留的，红色的是需要删除的不足结点。下面我来看下怎么计算每个结点的对应路径值和（下面简称路径和），从图2.1可以看出父结点的路径和列表为其子结点的路径和列表的并集，也就是我们可以通过递归的方式从叶结点开始构造路径和列表，根据二叉树的遍历类型可以得知这是一种后序遍历，而在计算叶结点的路径值时可以通过经其途径的所有祖先结点的值都相加传递过来。当某个结点的路径和列表值全部小于limit时，该结点即为『不足结点』，将该结点删除。

下面我们来看下怎么删除一个结点，对于非根结点来说，删除一个结点很简单，将其父结点对应的子结点置为null即可；如果是删除根结点root则直接将根结点置为null，但是这样在代码实现的时候比较麻烦，因为需要判断结点是否为根结点，这会导致代码中要做特殊处理，因此我们考虑能不能将代码统一不做特殊处理，一种比较简单的处理方法是给root增加一个父结点，这样root也就变成了一个非根结点了，处理方式即可同其他结点相同（至于root是作为新增加的父结点的左子结点还是右子结点没有区别），最后在返回的时候再返回我们增加的结点对应的子结点就行了。

根据以上的分析我们构造一个后序遍历，该后序遍历返回结点的路径和列表，而结点的路结和列表是将其左右子结点的路径和列表进行合并，同时如果结点的左子结点为『不足结点』则将结点的左子结点置为null，右子结点为『不足结点』则将结点的右子结点置为null，同时返回该结点的路径和列表。代码实现如下：


``` java
public TreeNode sufficientSubset(TreeNode root, int limit) {
    TreeNode temp = new TreeNode(0);
    temp.left = root;
    postorderTraversal(temp, limit, 0);
    return temp.left;
}

private int[] postorderTraversal(TreeNode node, int limit, int preSum) {
    if (node == null) {
        return new int[0];
    }

    int[] leftPath = postorderTraversal(node.left, limit, preSum + node.val);
    int[] rightPath = postorderTraversal(node.right, limit, preSum + node.val);

    boolean leftIsInsufficient = true;
    boolean rightIsInsufficient = true;
    for (int leftSum : leftPath) {
        if (leftSum >= limit) {
            leftIsInsufficient = false;
        }
    }

    for (int rightSum : rightPath) {
        if (rightSum >= limit) {
            rightIsInsufficient = false;
        }
    }

    if (leftIsInsufficient) {
        node.left = null;
    }

    if (rightIsInsufficient) {
        node.right = null;
    }

    int[] all = new int[leftPath.length + rightPath.length];
    System.arraycopy(leftPath, 0, all, 0, leftPath.length);
    System.arraycopy(rightPath, 0, all, leftPath.length, rightPath.length);

    if (all.length == 0) {
        all = new int[]{preSum + node.val};
    }
    return all;
}
```

执行结果如下：
![a184d266dccc6db737a6_728x499.png](https://pic.leetcode-cn.com/0cf4a4cc74ae3accc08f206ef4a27ff8ff009fb531432d0eae227b87d66ef191-a184d266dccc6db737a6_728x499.png)

# **方法二**
我们将方法1中图的路径和列表删除，同时将『不足结点』置为红色来看看有没有什么规律，重新转换后的图如下图所示。
![eab74266dccd4e46c99d_686x340.png](https://pic.leetcode-cn.com/cfabafa002e43a7ea00ed129e4034c7e2d64bc7d9731f269efbae81cab42b729-eab74266dccd4e46c99d_686x340.png)
从图中可以看出：一个结点为『不足结点』当且仅当其左右子结点全为『不足结点』，而叶结点是否为『不足结点』可以直接通过路径和来计算，由于结点为叶结点，而经过叶结点的“根-叶”路径只有一条，直接看其和和limit的关系即可。利用该性质可以对方法1进行改进，我们不需要计算每个结点的路径和列表，而是根据去左右子结点的情况来直接判断当前结点是否为『不足结点』，同样这也是一个后序遍历，在遍历的过程中将路径中的每个结点的值带下去，直到叶结点为止，如果是叶结点我们判断其路径和是否小于limit，小于limit则为『不足结点』。

根据以上的分析我们构造一个后序遍历，该后序遍历返回结点是否为『不足结点』，在计算时先看其左右子结点是否为『不足结点』，如果左子结点为『不足结点』则将结点的左子结点置为null，右子结点为『不足结点』则将结点的右子结点置为null，如果左右子结点均为『不足结点』则返回true，否认则返回false；如果结点为叶结点（左右子结点为null）返回路径和是否小于limit。代码实现如下：

``` java
public TreeNode sufficientSubset(TreeNode root, int limit) {
    TreeNode temp = new TreeNode(0);
    temp.left = root;
    isInsufficient(temp, 0, limit);
    return temp.left;
}

private boolean isInsufficient(TreeNode node, int preSum, int limit) {
    if (node == null) {
        return true;
    }

    if (node.left == null && node.right == null) {
        return preSum + node.val < limit;
    }

    boolean leftIsInsufficient = isInsufficient(node.left, preSum + node.val, limit);
    boolean rightIsInsufficient = isInsufficient(node.right, preSum + node.val, limit);
    if (leftIsInsufficient) {
        node.left = null;
    }
    if (rightIsInsufficient) {
        node.right = null;
    }
    return leftIsInsufficient && rightIsInsufficient;
}
```

执行结果如下：
![1f749266dccf098ee5c1_731x502.png](https://pic.leetcode-cn.com/98cf6006aaf8655bb98b6a80d2063622f9be744498a924a833df908247098fa1-1f749266dccf098ee5c1_731x502.png)
