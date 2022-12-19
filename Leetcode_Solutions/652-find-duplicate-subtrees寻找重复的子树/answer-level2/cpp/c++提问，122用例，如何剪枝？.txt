同样卡在了第122测试用例（单边超长树，且值都是0），寻思着应该要剪枝，用了个bool判断是不是单边树，还是会超时，所以有啥剪枝的好方法？？
```gradle
class Solution {
public:
    bool check(TreeNode* root){ //尝试剪枝，若整个树只有单边，则返回false.
        stack<TreeNode*> a;
        a.push(root);
        int l = 0;
        int r = 0;
        while(!a.empty()){
            TreeNode* temp = a.top();
            if(temp -> left){
                a.push(temp -> left);
                ++ l;
            }
            if(temp -> right){
                a.push(temp -> right);
                ++ r;
            }
        }
        if(l == 0 || r == 0){
            return false;
        }
        return true;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans = {};
        if(!root) return ans;
        if(!check(root)) return ans;
        unordered_map<string,int> st;
        stack<TreeNode*> next;
        next.push(root);
        while(!next.empty()){
            TreeNode *temp = next.top();
            next.pop();
            if(temp -> left){
                next.push(temp -> left);
            }
            if(temp -> right){
                next.push(temp -> right);
            }
            string cur;
            stack<TreeNode*> getStr;
            getStr.push(temp);
            stack <char> dir;
            while(!getStr.empty()){
                TreeNode *printNode = getStr.top();
                getStr.pop();
                if(printNode -> left){
                    getStr.push(printNode -> left);
                    dir.push('l');
                }
                if(printNode -> right){
                    getStr.push(printNode -> right);
                    dir.push('r');
                }
                char n2char = '0' + printNode -> val;
                cur = cur + n2char;
                if(!dir.empty()){
                    cur += dir.top();
                    dir.pop();
                }
            }
            if(!st.count(cur)){
                st[cur] = 1;
            }
            else{
                ++ st[cur];
            }
            if(st[cur] == 2){
                ans.push_back(temp);
            }

         }
        return ans;
    }
};
```
