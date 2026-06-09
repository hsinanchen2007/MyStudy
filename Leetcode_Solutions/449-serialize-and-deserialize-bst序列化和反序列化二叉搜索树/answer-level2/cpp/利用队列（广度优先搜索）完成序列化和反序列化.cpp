
```
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                res += "N#";
            }else{
                res += to_string(node->val) + "#";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){return NULL;}
        string node;
        int i = 0;
        while(i < data.size()){
            if(data[i] == '#'){
                break;
            }
            node += data[i];
            ++i;
        }
        
        TreeNode* res = new TreeNode(stoi(node));
        node = "";
        queue<TreeNode*> q;
        q.push(res);
        ++i;
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            while(i<data.size()){
                if(data[i] == '#'){
                    if(node != "N"){
                        curNode->left = new TreeNode(stoi(node));
                    }
                    node = "";
                    ++i;
                    break;
                }
                node += data[i];
                ++i;
            }
            while(i<data.size()){
                if(data[i] == '#'){
                    if(node != "N"){
                        curNode->right = new TreeNode(stoi(node));
                    }
                    node = "";
                    ++i;
                    break;
                }
                node += data[i];
                ++i;
            }
            if(curNode->left){
                q.push(curNode->left);
            }
            if(curNode->right){
                q.push(curNode->right);
            }
        }
        return res;
    }
};

```
