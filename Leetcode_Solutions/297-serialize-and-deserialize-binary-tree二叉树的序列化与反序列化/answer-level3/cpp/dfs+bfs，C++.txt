### 层次遍历，不能单纯返回，应该类似计算层数一样，每次将一层计算完成
```
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* now=q.front();
                q.pop();
                if(now==NULL) res+="#";
                else{
                    res=res+to_string(now->val)+' ';
                    q.push(now->left);
                    q.push(now->right);
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        int i = 0, j = 0;
        while(j<data.size() && data[++j]!=' ');  //找到head
        TreeNode* head = new TreeNode(stoi(data.substr(i, j-i)) );
        queue<TreeNode*> q;
        q.push(head);

        while(i<data.size()){
            TreeNode* now=q.front();
            q.pop();
            if(now==NULL) continue;

            i = ++j;
            if(i >= data.size())    break;
            if(data[i] == '#'){
                now->left = NULL;
            }else{
                while(j<data.size() && data[++j] != ' ');
                now->left = new TreeNode(stoi(data.substr(i, j-i)) );
            }
            q.push(now->left);

            i = ++j;
            if(i >= data.size())    break;
            if(data[i] == '#'){
                now->right=NULL;
            }else{
                while(j<data.size() && data[++j] != ' ');
                now->right = new TreeNode(stoi(data.substr(i, j-i)) );
            }
            q.push(now->right);
        }
        return head;
    }
};
```
### dfs
```
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return string();
        stringstream ss;
        dfs(root,ss);
        return ss.str();
    }
    
    void dfs(TreeNode* rt,stringstream& ss){
        if(!rt){
            ss << "# ";
            return ;
        }
        ss << to_string(rt->val) <<" ";
        dfs(rt->left,ss);
        dfs(rt->right,ss);
    }

    // Decodes your encoded data to tree.
    void rebuild(TreeNode* & rt,stringstream& ss){
        string t;
        ss >> t;
        if(t[0] == '#'){
            rt = NULL;
            return;
        }
        int v = stoi(t);
        rt = new TreeNode(v);
        rebuild(rt->left,ss);
        rebuild(rt->right,ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        TreeNode* rt = NULL;
        stringstream ss(data);
        rebuild(rt,ss);
        return rt;
    }
};
```
