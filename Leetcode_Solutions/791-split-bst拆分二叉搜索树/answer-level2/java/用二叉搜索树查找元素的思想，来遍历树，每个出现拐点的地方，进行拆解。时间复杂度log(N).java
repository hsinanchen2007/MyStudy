### 解题思路

还是要利用二叉搜索树的性质，不过自己写的太复杂了，看了Tao的题解，发现人家思路比我清晰的多了，代码也简洁很多，这里就说一下自己的理解了,时间复杂度是log(N),空间复杂度O(1)。

看下面文字描述的时候，大家最好用纸笔画一下图，一步步跟着走，比较好理解。不然还是很空洞，我自己写这个思路的时候，也是看着图写的。

返回的两个子树一个是tree.val <= V的子树，叫做smallTree，另一个就是tree.val > V的子树，叫做bigTree，这里我们可以用二叉搜索树的查找元素的思路，treeNode.val <= V的值加入到smallTree中，treeNode.val > V的值加入到bigTree中。一层一层往下走，用两个cur指针，记录smallTree和bigTree当前遍历在原始树中的节点。

当然，这只是大体的思路，因为在遍历过程中，是会有拐点的出现。

拐点的定义和数学上的定义类似，就是这个点之前如果是递增，这个点之后就变成递减，反之亦然。换到二叉搜索树中的意思就是，之前V>node.val，node就一直往右子树遍历，当某个节点满足V < node.val了，这个时候node就要开始往左子树遍历了。反之V < node.val时，node就一直往左子树遍历，当某个节点满足V > node.val了，这个时候node就要开始往右子树遍历了。这个时候的node就是拐点。

拐点的出现意味树要拆分了，以其中一种情况为例之前 V>node.val，现在V<node.val，node之前的节点都加入到smallTree中了（因为每一个node.val<V，都有node.left.val<V），此时V<node.val，那么node和node.right中的节点都是比V要大的，他们要加入到bigTree当中，而node.left中却可能存在比V大和比V小的元素（因为node.val>node.left.val,node>V，这时候无法确定node.left.val和V的大小）。那么之前的树在拐点之前就要断开，然后往node.left继续遍历，依旧采用查找的思路，直到出现拐点，再用处理拐点的思路。

总而言之，如果之前是向左孩子遍历，出现了向右的拐点，拐点和拐点的左孩子就要加入到smallTree中，拐点的父节点和父节点的右孩子都在bigTree中，bigTree的curNode指向拐点，拐点的右子树就要继续大小树处理，直到node为空或者到下一个拐点。
    
如果之前是想右孩子遍历，出现了向左的拐点，拐点和拐点的右孩子就要加入bigTree，拐点的父节点和父节点的左孩子都在smallTree,smallTree的curNode指向拐点，拐点的左子树继续大小树的处理，直到node为空或者到下一个拐点。
    
思路中并没有说明等于V的情况，加进去说明的情况就变复杂了，所以在思路中就不提了，代码中有具体的小于等于的实现。
    
最后写了挺多，感觉能看懂的人怕是不太多，有点乱，在理解这个思路的时候，还是要动笔画一下图。欢迎大家留言，描述不清楚的地方，我会继续更新的。

### 代码

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
    public TreeNode[] splitBST(TreeNode root, int V) {
        // 存储>V值的节点，本身是一个哨兵，不参与真正运算，简化实现
        TreeNode bigTreeNode = new TreeNode(Integer.MAX_VALUE);
        // 存储<=V值的节点，本身是一个哨兵，不参与真正运算，简化实现
        TreeNode smallTreeNode = new TreeNode(Integer.MAX_VALUE);
        // 当前bigTree的节点
        TreeNode curBigTreeNode = bigTreeNode;
        // 当前smallTree的节点
        TreeNode curSmallTreeNode = smallTreeNode;
        // node节点
        TreeNode node = root;
        while (node != null){
            if (node.val>V){
                // node.val比V大，加入到bigTree中
                // bigTree中操作
                if (node.val <= curBigTreeNode.val){
                    curBigTreeNode.left = node;
                }else {
                    curBigTreeNode.right = node;
                }
                // 当前大树指针移动
                curBigTreeNode = node;
                // 目标V在node的左子树中，node.right.val肯定都比V要大，全部都进入bigTree中
                node = node.left;
                // 之前node比V大，下一个节点的值比V小了，拐点出现，原来的树要断开了,bigTree中存的是比V大的值
                // 现在curBigTreeNode指向的node.parent节点，node.parent.left不能再加入到bigTree中，要断开
                // 但是node.parent.right中还是有可能要加入到bigTree中，这个在接下来的遍历中在bigTree操作中会处理到
                if (node != null && node.val <= V){
                    curBigTreeNode.left = null;
                }
            }else {
                // node.val比V小，加入到smallTree中
                // smallTree中操作
                if (node.val <= curSmallTreeNode.val){
                    curSmallTreeNode.left = node;
                }else {
                    curSmallTreeNode.right = node;
                }
                // 当前小树指针移动
                curSmallTreeNode = node;
                // 目标V在node的右子树中，node.left.val肯定都比V要小，全部都进入smallTree中
                node = node.right;
                // 之前node比V小，下一个节点的值比V大了，拐点出现，原来的树要断开了，smallTree中存的是比V小的值
                // 现在curSmallTreeNode指向的node.parent节点，node.parent.right不能再加入到smallTree中，要断开
                // 但是node.parent.left中还是有可能要加入到smallTree中，这个在接下来的遍历中在smallTree操作中会处理到
                if (node != null && node.val > V){
                    curSmallTreeNode.right = null;
                }
            }
        }
        return new TreeNode[]{smallTreeNode.left,bigTreeNode.left};
    }
}
```