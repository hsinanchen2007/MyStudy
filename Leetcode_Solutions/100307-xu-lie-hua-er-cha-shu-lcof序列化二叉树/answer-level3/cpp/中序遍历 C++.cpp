```
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { //生成中序遍历序列，包含NULL节点
        string s;
        queue<TreeNode*> q; //借助队列
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){ //空节点字符串s+" "+","，以逗号分隔节点
                s+=" ,"; 
                continue;
            }
            else //否则，字符串s+"node->val"+","
                s+=to_string(node->val)+",";
            q.push(node->left);
            q.push(node->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0, j = 0;
        vector<TreeNode*> t; //借助t来存储生成的节点
        while(i<data.size()){ //分隔字符串生成节点
            while(i+j<data.size() && data[i+j] != ',') j++;
            if(data.substr(i,j) == " ") //若为空格，生成空节点入队
                t.push_back(nullptr);
            else{ //否则生成新节点入队
                TreeNode* node = new TreeNode(atoi(data.substr(i,j).c_str()));
                t.push_back(node);
            }
            i += j+1; j=0;
        }
        if(t.size()==1) return t[0]; //空树或单节点树直接返回
        i=0; j=1;
        while(j<t.size()){ //遍历数组建立左右子树关系
            while(i<j && !t[i]) i++; //得到当前的第一个非空节点
            t[i]->left = t[j++]; //左子树为后续未遍历的下一个节点
            t[i]->right = t[j++]; //右子树为后续未遍历的下一个节点
            i++;
        }
        return t[0]; //返回根
    }
};
```
