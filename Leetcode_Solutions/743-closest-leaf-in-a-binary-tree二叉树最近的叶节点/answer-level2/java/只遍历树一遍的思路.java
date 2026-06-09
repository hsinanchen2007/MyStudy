### 解题思路
&emsp;距离k的最近叶节点分两种情况，即：
* 以k为根的子树中的叶节点；
* 以k的祖先结点为中转，且到祖先结点路径中不包含k的叶节点。

社区时间性能较好的算法就是树的遍历，递归方法返回标识标识当前路径是否包含k结点，如果包含则再次调用遍历方法遍历计算祖先结点不包含k结点分支的最短距离叶节点，虽然时间复杂度是$O(N)$，但要遍历多次树的结点。实质上这些操作都可以在一次遍历中搞定，无非就是递归方法返回更多的信息和标识。

&emsp;具体思路为返回三个元素的数组，第一位表示叶节点值，第二位表示到当前路径的距离，第三位表示路径中是否包含k结点。突然看到自己之前乱糟糟的、没注释的代码成为了运行1s的范例。。所以我重构代码，加了注释，希望大家能理解。重构之后的代码，使用`Integer`数组，而不是`int`数组，可以携带更多信息。这样递归终结可以从空结点开始，而非叶节点，省去左右叶节点的判断。空结点则返回`[null,0,0]`；当当前结点获取到左右子节点的值时，分如下情况：

* 当前结点是k结点，则选择子节点中路径最短的，并与最短距离比较更新，如果当前结点是叶节点，则距离为0；关键一点是返回距离重置为0的数组，表示以k为根的子树的距离以统计完成，从k结点开始统计计算到祖先结点的距离。如果是叶节点则返回`[k,0,1]`；如果不是叶节点，则返回`[null, 0, 1]`；
* 当前结点不是k结点，且子节点路径中不包含k结点，则只需选择距离最短的并返回；
* 当前结点不是k结点，子路径中包含k结点，则计算另一分支与包含k结点分支的距离，并更新，而返回只包含k结点的路径。

### 代码

```java
class Solution {
    int minDis = Integer.MAX_VALUE;
    int node = 0;

    public int findClosestLeaf(TreeNode root, int k) {
        if (root == null) throw new IllegalArgumentException("invalid param");
        postOrder(root, k);
        return node;
    }

    private Integer[] postOrder(TreeNode root, int k) {
        if (root == null) return new Integer[]{null, 0, 0};

        Integer[] left = postOrder(root.left, k);
        Integer[] right = postOrder(root.right, k);

        // 叶节点是k，则距离是0，已经是最短距离，直接返回
        if ((left[0] != null && left[0] == k) || (right[0] != null && right[0] == k)) return left[0] != null && left[0] == k ? left : right;

        Integer[] res;
        // 当前结点是k结点
        if (root.val == k) {
            res = getMinPath(left, right);
            // 说明是叶节点
            if (res[0] == null) {
                minDis = 0;
                node = k;
                res = new Integer[]{k, 0, 1};
            } else {
                if (minDis > res[1] + 1) {
                    minDis = res[1] + 1;
                    node = res[0];
                }
                // 重置k点的距离，返回从k出发到祖先结点的距离
                res = new Integer[]{null, 0, 1};
            }
        }
        // 子路径存在k结点，则计算更新并返回带k的路径
        else if (left[2] == 1) {
            if (right[0] != null && right[1] + left[1] + 2 < minDis) {
                minDis = right[1] + left[1] + 2;
                node = right[0];
            }
            res = left;
            res[1] += 1;
        } 
        else if (right[2] == 1) {
            if (left[0] != null && right[1] + left[1] + 2 < minDis) {
                minDis = right[1] + left[1] + 2;
                node = left[0];
            } 
            res = right;
            res[1] += 1;
        }
        // 子路径不带有k结点
        else {
            res = getMinPath(left, right);
            // 是叶节点
            if (res[0] == null) {
                res = new Integer[]{root.val, 0, 0};
            } 
            // 非叶节点，返回较小的路径
            else {
                res[1] += 1;
            }
        }

        return res;
    }

    // 返回距离较小的子节点
    private Integer[] getMinPath(Integer[] left, Integer[] right) {
        if (left[0] == null) return right;
        else if (right[0] == null) return left;

        return left[1] < right[1] ? left : right;
    }
}
```