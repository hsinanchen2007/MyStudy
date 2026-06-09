### 解题思路
    /*
     * 递归遍历
     *
     * 先需要确定树A中是否存在树B的根节点，
     * 如果不存在则直接返回false，存在则继续判断该节点后的左右子树是否也完全相同，
     * 遍历树B结束都相同则返回true，不同返回false。
     * 这里需要有两次递归，第一次是递归从树A中找到等于树B根节点的节点，
     * 第二次递归是从相同的节点开始，对树的左右子树判断是否树A完全包含树B。
     * */
### 代码
```cpp
bool isSubStructure(BiTreeNode<int> *A, BiTreeNode<int> *B) {
    // 空树不是任意一个树的子结构
    if (!A || !B) {
        return false;
    }

    // 不断遍历树A，直到找到与B根节点相等的点
    return dfs(A, B) || isSubStructure(A->leftChild, B) || isSubStructure(A->rightChild, B);
}

bool dfs(BiTreeNode<int> *A, BiTreeNode<int> *B) {
    // B为空表示B已经遍历结束，
    // 返回true
    if (!B) {
        return true;
    }

    // B不为空,A为空时，
    // 表示B不是A的子结构
    if (!A) {
        return false;
    }

    // 如果A中不存在B的根节点
    // 返回false
    if(A->data != B->data){
        return false;
    }

    // 如果A中存在B的根节点，则继续遍历左右子树是否也完全相同
    // 完全遍历过树B后，都符合则返回true
    return  dfs(A->leftChild, B->leftChild) && dfs(A->rightChild, B->rightChild);
}
```