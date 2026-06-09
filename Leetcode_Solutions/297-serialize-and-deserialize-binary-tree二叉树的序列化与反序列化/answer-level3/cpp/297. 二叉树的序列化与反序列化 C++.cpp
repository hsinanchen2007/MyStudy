### 解题思路
1、层序遍历 

2、先序遍历

### 代码

```cpp

class Codec {
public:

    //1、序列化  层序遍历 入队时拼串  
    string serialize(TreeNode* root) {

        if (root == nullptr)
        {
            return "";
        }

        string s = to_string(root->val) + ",";

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            //左子节点
            if (node->left)
            {
                s += to_string(node->left->val) + ",";
                q.push(node->left);
            }
            else
            {
                s += "null,";
            }

            //右子节点
            if (node->right)
            {
                s += to_string(node->right->val) + ",";
                q.push(node->right);
            }
            else
            {
                s += "null,";
            }
        }

        return s;
    }

    //反序列化  层序遍历  出队时，创建左、右子节点并串联
    TreeNode* deserialize(const string& data) {

        if (data.empty())
        {
            return nullptr;
        }

        vector<string> v = split(data, ","); //分割字符串

        queue<TreeNode*> q;

        int index = 0;
        TreeNode* root = generate_node(v.at(index));
        ++index;

        if (root)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            node->left = generate_node(v.at(index));
            ++index;

            if (node->left)
            {
                q.push(node->left);
            }

            node->right = generate_node(v.at(index));
            ++index;

            if (node->right)
            {
                q.push(node->right);
            }

        }
        return root;
    }


    //2、前序遍历 序列化
    string serialize(TreeNode* root) {

        if (root == nullptr)
            return "null,";

        string s = to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);

        return s;
    }

    //前序遍历 反序列化
    TreeNode* preorder_build(vector<string>& v, int& index)
    {
        string& s = v.at(index);
        ++index;

        if (s == "null")
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(s));
        node->left = preorder_build(v, index);
        node->right = preorder_build(v, index);

        return node;
    }

    TreeNode* deserialize(const string& data) {

        if (data.empty())
            return nullptr;

        vector<string> v = split(data, ","); //分割字符串

        int index = 0;
        return preorder_build(v, index);
    }


private:
    //创建节点
    TreeNode* generate_node(const string& data)
    {
        if (data == "null")
        {
            return nullptr;
        }

        return new TreeNode(stoi(data));
    }


    //分割字符串
    vector<string> split(const string& s, const char* delim)
    {
        vector<string> v;
        char* str = strtok((char*)s.c_str(), delim);
        while (str)
        {
            v.push_back(string(str));
            str = strtok(NULL, delim);
        }
        return v;
    }

};
