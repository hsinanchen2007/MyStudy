### 解题思路

处理逻辑很简单，就是每一次处理一层。

首先是root，循环1，取出root，加入两个子节点

接着队列长度为2，循环2次，依次取出节点，然后加入节点的子节点，假如是4.

于是队列长度为4，循环4次，依次取出节点，然后加入节点的子节点，假如是8.

。。。

直到所有节点都被处理


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        //如果为空，直接返回
        if (root == nullptr) return res;
        //新建一个队列,用于依次加入节点
        queue<TreeNode*> myque;
        myque.push(root); //加入第一个节点
        while( ! myque.empty() ){
            //当前层的结果
            vector<int> curr;
            int level_size = myque.size(); //获取目前队列长度
            for (int i = 0; i < level_size; i++){
                //取出元素
                TreeNode *node = myque.front();
                myque.pop();
                //加入到curr中
                curr.push_back(node->val);
                //加入节点的自己节点
                if(node->left != NULL) myque.push(node->left);
                if (node->right != NULL) myque.push(node->right);
            }
            //加入每一层的结果
            res.push_back(curr);
        }
        return res;
    }
};
```