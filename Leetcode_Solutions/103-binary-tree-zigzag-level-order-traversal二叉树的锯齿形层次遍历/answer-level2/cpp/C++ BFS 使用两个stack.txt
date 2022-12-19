```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        stack<TreeNode *> st;       //当前层的节点
        TreeNode *node;
        st.push(root);
        bool flag = true;
        while(!st.empty()){
            vector<int> arr;
            stack<TreeNode *> tmpst;    //存储下一层节点
            int n = st.size();
            while(n--){
                node = st.top();
                st.pop();
                arr.push_back(node->val);
                if(flag){               //flag=true入栈顺序为左-->右，flag=false入栈顺序为右-->左
                    if(node->left) tmpst.push(node->left);
                    if(node->right) tmpst.push(node->right);
                }
                else{
                    if(node->right) tmpst.push(node->right);
                    if(node->left) tmpst.push(node->left);
                }
            }
            flag = !flag;
            st = tmpst;             //一层遍历完换下一层
            res.push_back(arr);
        }
        return res;
    }
};
```
