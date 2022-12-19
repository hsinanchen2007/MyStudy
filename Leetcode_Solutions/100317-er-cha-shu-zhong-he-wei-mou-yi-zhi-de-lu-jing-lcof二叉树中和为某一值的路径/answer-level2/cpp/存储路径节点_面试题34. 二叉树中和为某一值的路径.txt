### 解题思路
    /*
     * 存储路径节点法
     * 因为是计算二叉树根节点到叶节点路径上节点值的和，
     * 可以使用前序遍历对二叉树进行遍历。
     *
     * 但问题是访问路径的和不一定等于目标值sum，
     * 所以需要将该路径的所有点存储起来，如果该路径的和不等于sum，
     * 则从叶节点开始回溯。递归的方法本身含有回溯的操作，
     * 所以我们需要做的就是怎么存储路径上的节点。
     *
     * 因为需要存储节点和删除节点的操作，所以使用栈是好的结构。
     * 但又需要对路径和等于sum的路径节点进行存储返回，
     * 所以改使用std::vector，同样能进行尾部添加和删除操作。
     * 同时使用全局变量，方便对正确路径节点进行返回。
     *
     * 1. 访问根节点，将根节点的值累加到当前路径和curSum；
     * 2. 判断当前节点是否为叶节点，如果当前节点是叶节点，
     *    且根节点到当前叶节点路径和curSum等于sum，
     *    则将该路径上的节点存入结果数组中。
     *    接着弹出该叶节点，对二叉树其他节点继续遍历，找到其他正确的路径。
     * 3. 如果当前节点是非叶节点，它的左子节点不为空则递归遍历其左子树，
     *    它的右子节点不为空则递归遍历其右子树。
     * 4. 继续步骤1,2的操作，依次类推。
     * */
### 代码

```cpp
private:
    std::vector<std::vector<int>> ans;
    std::vector<int> pathAns;

public:
std::vector<std::vector<int>> pathSum(BiTreeNode *root, int sum) {
    if(root == nullptr){
        return {};
    }
    
    // 存储路径节点的数组
    std::vector<int> path;
    // 当前路径和
    int curSum = 0;
    
    findPath(root, sum, path, curSum);

    return ans;
}

void findPath(BiTreeNode *root, int sum, std::vector<int>& path, int curSum) {
    // 将当前节点值累加到当前路径和
    curSum += root->val;
    // 将当前节点压入存储路径节点数组中
    path.push_back(root->val);

    // 判断当前节点是否为叶节点
    bool isLeaf = (root->left == nullptr) && (root->right == nullptr);

    // 如果当前节点是叶节点，且当前路径和满足条件
    if(curSum == sum && isLeaf){
        // 将该路径上的节点值返回
        for(int & p : path){
            pathAns.push_back(p);
        }
        ans.push_back(pathAns);
        // 对当前路径存储数组置空
        pathAns = {};
    }

    // 如果当前节点是非叶节点，判断该节点左子节点是否为空，
    // 如果不为空，则对左子树进行递归遍历
    if(root->left != nullptr){
        findPath(root->left, sum, path, curSum);
    }
    
    // 如果当前节点是非叶节点，判断该节点右子节点是否为空，
    // 如果不为空，则对右子树进行递归遍历
    if(root->right != nullptr){
        findPath(root->right, sum, path, curSum);
    }

    path.pop_back();
}
```