![image.png](https://pic.leetcode-cn.com/62a2a69f528b17ad629d39f5606d7bceaa9baad847739c04829cdc25620a31b0-image.png)

## 注意：
```
我刚开始的时候只注意了序列化的时候把节点后加特殊符号分开，却忽略了根节点处的问题
比如母树只有根节点12，子树只个节点2。如果不处理根节点则序列化后
s1:12_#_#_
s2:2_#_#_
明明应该是输出false却变成了true
所以要在根节点前加一个特殊符号做出节点分割，保证每个节点前后都独立，就可以通过~
```


Code：
```
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
    string tree_To_string(TreeNode* tree){
        if(tree == NULL)    return "#_";
        string str = "?"+to_string(tree->val)+"_";
        return  str + tree_To_string(tree->left) + tree_To_string(tree->right);
    }
    vector<int> GetNextArr(string str){
        int len = str.length();
        vector<int>next(len);
        next[0] = -1;
        next[1] = 0;
        int cn = 0;
        int pos = 2;
        while(pos < next.size()){
            if(str[pos-1] == str[cn]){
                next[pos++] = ++cn;
            }else if(cn>0){
                cn = next[cn];
            }else{
                next[pos++] = 0;
            }
        }
        return next;
    }
    int GetIndex(string s1, string s2){
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 == 0 || len2 == 0 || len1 < len2 || s1.empty() || s2.empty()){
            return -1;
        }
        vector<int> next = GetNextArr(s2);
        int i = 0;
        int j = 0;
        while(i < len1 && j < len2){
            if(s1[i] == s2[j]){
                i++,j++;
            }else if(next[j] == -1){
                i++;
            }else{
                j = next[j];
            }
        }
        return j == len2 ? i-j : -1;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string s1 = tree_To_string(s);
        //cout<<s1<<endl;
        string s2 = tree_To_string(t);
        //cout<<s2<<endl;
        return GetIndex(s1,s2)!=-1;
    }
};







```
