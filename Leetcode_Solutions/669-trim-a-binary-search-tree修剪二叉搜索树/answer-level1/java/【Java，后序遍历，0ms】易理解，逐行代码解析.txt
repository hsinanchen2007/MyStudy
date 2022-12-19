> 思路

题目是给定一个区间[ L,R ] 来修剪一个BST。

我这里使用的是`树的后序遍历的思想`，因为我一开始没什么思路，就想着这个要一层一层遍历修剪，用后序试试准没错。

那么根据后序遍历，即左右中的处理方式

具体代码我在下面讲



<br>

> 代码

1. 首先，判断当前节点是否为null，为null则直接return
2. 后序遍历的左，对左子节点进行递归
3. 后序遍历的右，对右子节点进行递归
4. 最后处理自己
     题目要求是[L,R],我们这里反着判断即可（少判断一次这样）
     1. `root.val < L` , 当前节点的值**小于**L，那么根据BST的特性，我们知道只有`右子节点`有希望替代`当前节点`。（如果右子节点为null，当前节点直接被裁剪）
          这里要记住return，否则下面容易出现`空指针异常`
     2. `root.val > R `, 当前节点的值**大于**R，那么根据BST的特性，我们知道只有`左子节点`有希望替代`当前节点`。（如果左子节点为null，当前节点直接被裁剪）
          这里要记住return，否则下面容易出现`空指针异常`
     3. 经过前面两轮判断，此时root肯定在L,R之间。
          那么我们只需要让`root.left=left`和`root.right=right`即可，因为经过后序遍历，拿到的left和right都经过前面的重重判断
          要么为null，要么就是符合情况。
5. 处理完自己后，return自己即可。
     根据后序遍历，这个root即根节点。


<br>
```java
    public TreeNode trimBST(TreeNode root, int L, int R) {

        if (root == null) {
            return null;
        }

        TreeNode left = trimBST(root.left, L, R);
        TreeNode right = trimBST(root.right, L, R);


        if (root.val < L) return root = right;

        if (root.val > R) return root = left;


        root.left = left;
        root.right = right;

        return root;

    }
```

