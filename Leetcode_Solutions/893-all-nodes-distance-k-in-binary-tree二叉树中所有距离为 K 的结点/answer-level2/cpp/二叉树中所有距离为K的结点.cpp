### 解题思路
后序遍历+深度优先遍历

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> resVec;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        //特殊情况：root或者target为空
        if (root == NULL || target == NULL){
            return {};
        }
        //特殊情况：K == 0，只有target本身
        if (K == 0){
            return {target->val};
        }
        myDFS(root, target, K);//后序遍历二叉树
        return resVec;
    }
    //后序遍历以root为根的二叉树，并且返回root的父节点到target的距离
    int myDFS(TreeNode* root, TreeNode* target, int K){
        if (root == NULL){
            return -1;//返回-1，说明距离无穷大
        }
        if (root == target){//特殊情况
            helper(root, K);//取出以root为根的距离为K的元素
            return 1;//root的父节点到target的距离为1
        }
        //如果target在root的左子树
        int distance = myDFS(root->left, target, K);
        //更新distance记录的是root->left的父节点root到target的距离
        if (distance != -1 && K >= distance){
            if (K == distance){//如果root到target的距离刚好为K
                resVec.push_back(root->val);
                return -1;
            }
            else {
                //否则搜索root->right距离target == K的节点
                //root到target的距离为distance，root->right到target的距离为distance + 1
                helper(root->right, K - (distance + 1));
                return distance + 1;
            }
        }
        //如果target在root的右子树
        distance = myDFS(root->right, target, K);
        //更新distance记录的是root->right的父节点root到target的距离
        if (distance != -1 && K >= distance){
            if (K == distance){//如果root到target的距离刚好为K
                resVec.push_back(root->val);
                return -1;
            }
            else {
                //否则搜索root->left距离target == K的节点
                //root到target的距离为distance，root->left到target的距离为distance + 1
                helper(root->left, K - (distance + 1));
                return distance + 1;
            }
        }
        return -1;//否则target到root的父节点的距离无穷大
    }
    //获取以root为根，到达root的距离为K的节点
    void helper(TreeNode* root, int K){
        if (root == NULL || K < 0){
            return;
        }
        if (K == 0){
            resVec.push_back(root->val);
        }
        else{
            helper(root->left, K - 1);
            helper(root->right, K - 1);
        }
    }
};

```