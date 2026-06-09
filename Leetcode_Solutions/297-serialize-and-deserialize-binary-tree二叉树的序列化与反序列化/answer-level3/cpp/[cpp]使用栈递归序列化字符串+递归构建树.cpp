在序列化的时候使用了一个栈而不是递归。反序列化时使用了递归。
```cpp
class Codec {
public:
    string serialize(TreeNode* root) {
        string ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())//这个步骤和先序是u一样
        {
            TreeNode* p = s.top();
            s.pop();
            if(p) {
                    s.push(p->right);
                   s.push(p->left);
                  ret += to_string(p->val) + ",";
                  }
            else
                ret += "n,";
        }
        ret.erase(ret.end()-1);//把尾巴上多的一个逗号去掉
        return ret;
    }
    TreeNode* deserialize(string data) {
        TreeNode* ret;
        stringstream ss;
        ss << data;
        string temp;
        vector<string> str_list;
        while(getline(ss, temp, ','))
        {
            str_list.push_back(temp);//和python里的split一个功能
        }
        int start = 0;
        ret = createTree(str_list, start); //start指示起点位置
        return ret;
    }
    //创建二叉树是常见的递归思路
    TreeNode* createTree(const vector<string> &str_list, int &start){
        if(str_list[start] == "n") //边界条件：节点为空
        {
            start++;
            return nullptr;
        }
        TreeNode* root;
        root = new TreeNode(stoi(str_list[start]));
        start++;
        
        root->left = createTree(str_list, start);
        root->right = createTree(str_list, start);
        return root;
    }
};
```
