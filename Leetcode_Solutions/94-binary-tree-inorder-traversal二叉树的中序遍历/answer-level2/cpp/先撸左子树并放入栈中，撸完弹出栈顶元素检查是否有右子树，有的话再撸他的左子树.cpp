### 解题思路
先沿着根节点撸，撸完所有的左子树并放入栈中，然后从栈中取出数据放入输出向量中，并检测当前节点是否有右子树，有的话继续撸完他所有的左子树，循环结束

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
    //需要寻找种子节点的所有左孩子，并将他们放入st栈中
    int seach_left(stack<TreeNode*>* st,vector<int>* vec){
        TreeNode* seed = st->top();
        //cout << "***********" << seed->val << "***********" << endl;
        while(seed->left)
        {
            //cout << "***********" << seed->val << "***********" << endl;
            //cout << "   seed->left.val: " << (seed->left)->val << endl;
            // if(!(*vec).empty())
            // {
            //     if((*vec)[(*vec).size()-1] == (seed->left)->val)
            //     {
            //         cout << "come in" << endl;
            //         cout << "Vec.back() " << (*vec)[(*vec).size()-1] << endl;
            //         return 0;
            //     }
            // }
            st->push(seed->left);
            seed = seed->left;
            
        }
        //cout << "           ////end" << endl;
        return 1;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> st;
        int ret;
        int flag = 0;
        TreeNode* mbr;
        if(!root)//检测是否为null,检测为null则返回output
            return output;
        st.push(root);
        while(!st.empty()){
            if(flag == 0)
            {
                ret = seach_left(&st,&output);    //读取并返回当前节点的所有左节点
                flag = 1;
            }
                
            output.push_back((*st.top()).val);//将栈顶元素放入输出队列中
            mbr = st.top();                   //保存栈顶节点，寻找右侧节点
            st.pop();               
            if(mbr->right)
            {
                st.push(mbr->right);
                flag = 0;
            }
                
            
            //cout << "output.val " << output.back() << endl;
        }
        return output;
    }
};
```