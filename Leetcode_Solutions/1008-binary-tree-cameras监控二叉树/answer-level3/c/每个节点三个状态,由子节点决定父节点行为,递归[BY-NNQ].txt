### 解题思路
> 这个题目的转换思想比较难以想到, 类似于DP的递推思想, 可以从叶子节点的状态来决定父节点的状态; 状态主要有3种; 由于二叉树没法从子节点往父节点很方便的遍历, 所以此处用的递归做的; 后面有时间再用迭代做一个; 主要流程如下:
- 1. 初始化叶子节点为 状态0 => 未放置状态; 注意:迭代遍历的时候, NULL指针的不是叶子节点,而是叶子节点的子节点,所以设置NULL节点为不用管的 Covered状态;
- 2. 递归判定,
    - 2.1 如果当前节点的子节点有一个处于未照亮状态, 则当前节点必须放一个 camera, 返回状态 2;
    - 2.2 如果当前节点的子节点有一个有camera, 则当前节点会被覆盖点亮, 啥都不用做, 返回状态 1;
    - 2.3 不满足上面两种情况, 则当前节点状态为未放置状态 0 ;

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define NODE_STATUS_UNTOUCHED 0
#define NODE_STATUS_COVERED 1
#define NODE_STATUS_CAMERA 2

int DfsCheckNode(struct TreeNode *node, int *count)
{
    if (node == NULL) {
        return NODE_STATUS_COVERED;
    }
    int left = DfsCheckNode(node->left, count);
    int right = DfsCheckNode(node->right, count);
    if (left == NODE_STATUS_UNTOUCHED || right == NODE_STATUS_UNTOUCHED) {
        *count += 1;
        return NODE_STATUS_CAMERA;
    }

    if (left == NODE_STATUS_CAMERA || right == NODE_STATUS_CAMERA) {
        return NODE_STATUS_COVERED;
    }

    return NODE_STATUS_UNTOUCHED;
}

int minCameraCover(struct TreeNode *root)
{
    int count = 0;
    int status = DfsCheckNode(root, &count);
    if (status == NODE_STATUS_UNTOUCHED) {
        count += 1;
    }
    return count;
}

```

### time 
```
执行用时 :8 ms, 在所有 C 提交中击败了82.98%的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了100.00%的用户
```
