### 解题思路
我的办法比较简单，在我看来二叉树在掌握了其遍历方法之后和数组没有太大的区别。二叉搜索树的中序遍历就是一个升序的数组，那么我们的问题就被简化成在升序数组中查找众数的问题。
为了优化程序我选用了非递归的中序遍历。在遍历过程中，我们需要将当前节点的值与前一个节点的值相比较，然后更新curTime的值。
1，如果pre->val == node->val更新完curTime的值后，我们将其与当前遇到的最大重复次数（maxTime）相比较。会有三种结果，
（1）curTime<maxTime，不需要处理，（2）curTime == maxTime 将当前node->val加入res中（此时node->有可能是众数之一，加入即可，万一不是，会在下一种情况时做处理）（3）curTime>maxTime 更新maxTime,清除res(说明之前所有的答案将不再合适)，将node->val加入到res中。。
2，如果pre->val 不等于 node->val，curTime = 1；此时有一种特殊情况需要处理，那就是所有节点数目均为1时，在这里也需要将node->val加入到res中

最后，遍历的初始条件也需要处理，即pre==NULL的情况，要考虑清楚，设置好curTime和maxTime的值。


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
    void inorderTravel(TreeNode* root,std::vector<int>& res)
    {
        if(!root)   return;
        
        std::stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* pre = NULL;
        int curTime = 0;
        int maxTime = 0;
        
        while(node != NULL || !st.empty())
        {
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else if(!node && !st.empty()){
                node = st.top();
                st.pop();

                if(!pre){
                    curTime = 1;
                    maxTime = 1;
                    pre = node;
                    if(curTime == maxTime)
                    {
                        res.push_back(node->val);
                    }

                    if(curTime>maxTime)
                    {
                        maxTime = curTime;
                        res.clear();
                        res.push_back(node->val);
                    }
                    node = node->right;
                    continue;
                }

                if(pre->val == node->val)
                {
                    curTime++;
                    if(curTime == maxTime)
                    {
                        res.push_back(node->val);
                    }
                    
                    if(curTime>maxTime)
                    {
                        maxTime = curTime;
                        res.clear();
                        res.push_back(node->val);
                    }
                }else{
                    curTime = 1;
                    if(curTime == maxTime )
                    {
                        res.push_back(node->val);
                    }
                }

                pre = node;
                node = node->right;
            }
        }
    }

    vector<int> findMode(TreeNode* root) {
        std::vector<int> res;
        if(!root)   return res;
        inorderTravel(root,res);

        return res;
    }
};
```