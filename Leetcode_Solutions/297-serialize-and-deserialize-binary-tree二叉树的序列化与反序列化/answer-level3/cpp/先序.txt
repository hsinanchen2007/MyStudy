### 解题思路
注意逗号一定要加上用来识别两位数

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string res;
       dfs1(root,res);
       return res;
    }
    void dfs1(TreeNode* root,string& res){
        if(!root){
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        dfs1(root->left,res);
        dfs1(root->right,res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        for(int i = 0;i < data.size();++i)cout << data[i];
        int index = 0;
        return dfs2(data,index);
    }
    TreeNode* dfs2(string& data,int& index){
        if(index > data.size()-1 || data[index] == '#'){
            index += 2; 
            return NULL;
        }

        bool flag = true;//false:负数   true:正数
        TreeNode* root = NULL;
        int tmp = 0;

        if(data[index] == '-'){
            flag = false;
            ++index;
        } 
        while(data[index] != ','){
            tmp = tmp*10+data[index] - '0';
            ++index;
        }
        ++index;

        if(flag)
            root = new TreeNode(tmp);
        else 
            root = new TreeNode(0-tmp);

        root->left = dfs2(data,index);  
        root->right = dfs2(data,index);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```