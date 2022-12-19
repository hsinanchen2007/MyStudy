### 解题思路
    /*
     * 递归判断
     *
     * 二叉搜索树是右子树的节点大于根节点，根节点大于左子树的节点，
     * 则二叉搜索树的后序遍历数组，最后一个数是根节点的值，
     * 根节点左边大于根节点的值是右子树节点的值，小于根节点的值是左子树节点的值。
     *
     * 根据上述二叉搜索树的特点，可以使用递归方法对后序遍历二叉树的数组进行判断。
     * 先从左往右遍历数组，当数值小于根节点的数值时，指针右移，此时遍历的是左子树的节点。
     * 直到找到第一个大于根节点的值，跳出循环，记录此时的索引 i 。
     * 从第一个大于根节点的值开始右移指针，当遍历到小于根节点的值时，
     * 表示不是二叉搜索树，返回false，若无则继续遍历。
     *
     * 因为索引 i 处的值是第一个大于根节点的值，所以该处左边是左子树的节点，
     * 右边不包括根节点是右子树的节点。这样就可以划分出左子树和右子树，
     * 分别按照上述的过程进行递归判断。
     * */

### 代码

```cpp
bool verifyPostorder(std::vector<int> &postorder) {
    if(postorder.empty()){
        return true;
    }

    return helper(postorder, 0, postorder.size()-1);
}

bool helper(std::vector<int> &postorder, int start, int end) {
    // 根节点是数组的最后一个值
    int root = postorder[end];

    // 从数组左边开始，
    // 小于根节点的值是左子树的节点，
    // 当遇到第一个大于根节点的值，
    // 跳出当前循环，记录索引 i
    int i = start;
    while (postorder[i] < root){
        i++;
    }

    // 从索引 i 处继续向右遍历，
    // 向右是右子树的节点，
    // 如果遇到小于根节点的值，
    // 则表明不是二叉搜索树，返回false
    int j = i;
    while (j < end){
        if(postorder[j] < root){
            return false;
        }

        j++;
    }

    // 如果左右子树可以按照索引 i 划分，
    // 将左子树部分进行递归判断
    // start是起始索引，i-1是结束索引
    bool leftTree = true;
    if(i > start){
        leftTree = helper(postorder, start, i - 1);
    }

    // 将右子树部分进行递归判断
    // 不包括根节点，
    // i是起始索引，end-1是结束索引
    bool rightTree = true;
    if(i < end - 1){
        rightTree = helper(postorder, i, end-1);
    }

    return leftTree && rightTree;
}
```