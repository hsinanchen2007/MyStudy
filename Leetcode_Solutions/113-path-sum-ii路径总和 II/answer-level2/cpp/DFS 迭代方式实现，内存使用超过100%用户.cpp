DFS一般用栈实现，此处用vector来代替栈，代码中使用数据类型为vector<pair<TreeNode*, int>>， 方便将某条符合条件的路径加入到返回的总集合results中
pair<TreeNode*, int>中，TreeNode*表示当前节点；int值，分别取值0,1,2 ，分别表示左右孩子未被访问，左孩子已被访问，右孩子已被访问。
类似于遍历图的时候会使用一个bool型的visited数组记录节点是否被访问过。
```
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> results; //存储返回的集合
        if (!root) return results;
        vector<pair<TreeNode*, int>> nodes; //用vector模拟栈，pair<first, second> first代表当前二叉树的节点，
                                            //second取值为0、1、2，0表示当前节点的左右孩子节点未被访问，1表示左孩子被访问，2表示右孩子被访问
        vector<int> vals;                   //存储nodes集合中二叉树节点对应的值
        int cur_sum = 0;
        nodes.push_back(pair(root, 0));
        cur_sum += root->val;
        vals.push_back(root->val);
        while(!nodes.empty()) {
            TreeNode* node = nodes.back().first;
            int& visitOrder = nodes.back().second;
            if (visitOrder == 0) {  // 当前节点左右孩子未被访问
                if (node->left == NULL && node->right == NULL) {  //表示当前节点为叶节点
                    if (cur_sum == sum) {
                        results.push_back(vector<int>(vals));
                    }
                    cur_sum -= *vals.rbegin();
                    vals.pop_back();
                    nodes.pop_back();
                } else if (node->left != NULL) {  //当前节点有左孩子，左孩子入栈，继续向下搜索
                    visitOrder = 1;
                    nodes.push_back(pair(node->left, 0));
                    vals.push_back(node->left->val);
                    cur_sum += node->left->val;
                } else if (node->right != NULL) { //当前节点有右孩子，右孩子入栈，继续向下搜索
                    visitOrder = 2;
                    nodes.push_back(pair(node->right, 0));
                    vals.push_back(node->right->val);
                    cur_sum += node->right->val;
                }
            } else if (visitOrder == 1) {  //当前节点左孩子已被访问
                if (node->right == NULL) { //当前节点没有右孩子，当前节点出栈
                    cur_sum -= *vals.rbegin();
                    vals.pop_back();
                    nodes.pop_back();
                } else {  //当前节点有右孩子，右孩子入栈，继续向下搜索
                    visitOrder = 2;
                    nodes.push_back(pair(node->right, 0));
                    vals.push_back(node->right->val);
                    cur_sum += node->right->val;
                }
            } else if (visitOrder == 2){ //当前节点右孩子已被访问，直接出栈
                cur_sum -= *vals.rbegin();
                vals.pop_back();
                nodes.pop_back();
            }
        }
        return results;
    }
};
```
