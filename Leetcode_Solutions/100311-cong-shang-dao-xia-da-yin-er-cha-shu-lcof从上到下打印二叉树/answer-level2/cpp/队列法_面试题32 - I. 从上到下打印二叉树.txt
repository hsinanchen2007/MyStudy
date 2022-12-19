### 解题思路
    /*
     * 队列法
     *
     * 因为要对二叉树进行层序遍历，所以不能使用递归方法。
     * 可以使用队列先进先出的特点对节点进行处理。
     * 先将根节点进队，取队首节点存入结果数组中，出队；
     * 如果根节点的左右子节点都不为空，则将左节点和右节点按顺序入队，
     * 依次取队首加入结果数组，再判断该节点的左右子节点是否为空，
     * 不为空则入队。重复上述操作，直到队列为空。
     * */
### 代码

```cpp
std::vector<int> levelOrder(BiTreeNode *root) {
    if(root == nullptr){
        return {};
    }
    
    // 结果数组
    std::vector<int> ans;
    
    // 存储二叉树节点的队列
    std::deque<BiTreeNode*> deq;

    // 先将根节点入队
    deq.push_back(root);

    // 队列不为空时循环
    while (!deq.empty()){
        // 取队首元素
        BiTreeNode* popNode = deq.front();
        // 队首元素出队
        deq.pop_front();
        // 将队首元素加入结果数组
        ans.push_back(popNode->val);

        // 判断出队的队首节点的左节点是否为空，
        // 不为空则入队
        if(popNode->left != nullptr){
            deq.push_back(popNode->left);
        }
        
        // 判断出队的队首节点的右节点是否为空，
        // 不为空则入队
        if(popNode->right != nullptr){
            deq.push_back(popNode->right);
        }
    }

    return ans;
}

```