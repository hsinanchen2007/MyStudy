## 解题思路

按照 leetcode 推荐序列化二叉树的格式来求解这道题。

那么，序列化树应该使用层次遍历，将树中所有的节点按照层次遍历获取到对应的值，将获取的值先保存到数组中去，最后拼接成标准结构返回。需要注意的是对于空节点的处理，这里遇到空节点是向数组中存入 null，这样会导致数组末尾多出很多的 null，需要在最后处理掉。

相对应的反序列化就是将上面序列化好的字符串再恢复成一颗二叉树。这里因为使用的是层次遍历来序列化二叉树，所以也得使用层次遍历来建立二叉树。首先得从字符串中获取到所有节点的值，保存在数组中，之后使用层次建树的方式来创建二叉树。

其中，有些需要注意的点：

- 对于空二叉树的处理序列化和反序列化要一致
- 二叉树中的节点的值有可能是负数，需要单独处理
- 层次遍历二叉树和建立二叉树的过程中都需要用到队列

## 代码

```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        string res;
        vector<string> con;
        queue<TreeNode*> q;
        q.push(root);
        // 层次遍历树
        while(!q.empty()){
            TreeNode* node = q.front();
            if(!node){
                con.push_back("null");
                q.pop();
                continue;
            }else con.push_back(to_string(node->val));
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        // 去除vector后面的多余null
        int n = con.size();
        while(con[--n]=="null");
        // 拼接结果字符串
        res+="[";
        for(int i=0;i<=n;i++){
            if(i==n) res+=con[i]+"]";
            else res+=con[i]+",";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n<=2) return nullptr;
        vector<int> con;
        // 获取字符串中的节点数据
        for(int i=1;i<n-1;i++){
            int num = 0;
            int fu = 1;
            if(data[i]=='n') {
                i+=4;
                num = -999;
            }
            while((i<n-1)&&data[i]!=',') {
                // 负数处理
                if(data[i]=='-'){
                    fu = -1;
                    i++;
                }
                num = num*10+data[i++]-'0';
            }
            con.push_back(num*fu);
        }
        // 层次建树
        int i = 0;
        int siz = con.size();
        TreeNode* root = new TreeNode(con[i]);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) continue;
            // 当前节点左节点
            if((2*i+1)<siz&&con[2*i+1]!=-999){
                node->left = new TreeNode(con[2*i+1]);
            }else{
                node->left = nullptr;
            }
            // 当前节点右节点
            if((2*i+2)<siz&&con[2*i+2]!=-999){
                node->right = new TreeNode(con[2*i+2]);
            }else{
                node->right = nullptr;
            }
            q.push(node->left);
            q.push(node->right);
            i++;
        }
        return root;
    }
};
```