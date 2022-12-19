```
//执行结果：通过显示详情执行用时 :28 ms, 在所有 C++ 提交中击败了73.96%的用户
//内存消耗 :11.3 MB, 在所有 C++ 提交中击败了100.00%的用户
//根据先序的性质当前层的上一层一定是其父节点
class Solution {
public:
    int index,val,len,cnt;
    unordered_map<int,TreeNode*> mp;//记录每层的结点（会变化）
    TreeNode* recoverFromPreorder(string s) {
        len = s.length();
        while(index<len&&s[index]!='-') val = 10*val + s[index++] - '0';
        TreeNode* root = new TreeNode(val);
        mp[0] = root;
        while(index<len) {
            cnt = 0;
            while(index<len&&s[index]=='-') cnt++,index++;
            val = 0;
            while(index<len&&s[index]!='-') val = 10*val+ s[index++] - '0';
            if(mp[cnt-1]->left) {
                mp[cnt-1]->right = new TreeNode(val);
                mp[cnt] = mp[cnt-1]->right;
            }
            else {
                mp[cnt-1]->left = new TreeNode(val);
                mp[cnt] = mp[cnt-1]->left;
            }
        }
        return root;
    }
};

 
```
