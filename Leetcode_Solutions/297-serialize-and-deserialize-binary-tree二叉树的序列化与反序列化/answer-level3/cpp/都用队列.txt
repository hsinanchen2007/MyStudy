### 解题思路
stringstream用于数据转换
当int等转换成string时，要用stringstream::str("")来清空缓存，不然会保存上次的内容。
当string转换成int等时，要用stringstream::clear()来清空，不然会一直输出上次的东西。

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
        string res = "[";
        stringstream ss;
        queue<TreeNode *> que;
        //que.push(root);
        if(root == NULL)
        {
            res.append("null]");
            return res;
        }
        else
        {
            ss << root->val;
            res.append(ss.str());
            que.push(root->left);
            que.push(root->right);
        }
        while (!que.empty())
        {
            TreeNode *p = que.front();
            que.pop();
            if (p == NULL)
            {
                res.append(",null");
            }
            else
            {
                ss.str("");
                ss << p->val;
                res.append("," + ss.str());
                que.push(p->left);
                que.push(p->right);
            }
        }
        res.append("]");
        //cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[1] == 'n')
        {
            return NULL;
        }
        vector<string> sp;
        string delim = ",";
        stringstream ss;
        split(data.substr(1, data.size()-2), delim, sp);
        /////////
        /*
        cout << data << "\n>>\n";
        for (auto c : sp)
        {
            cout << c << endl;
        }
        */
        if (sp[0][0] == 'n')
        {
            return NULL;
        }

        ss << sp[0];
        int temp;
        ss >> temp;
        ss.str("");
        TreeNode *root = new TreeNode(temp);
        queue<TreeNode *> que;
        que.push(root);
        int i = 1;
        while (!que.empty() && i < sp.size())
        {   
            //cout << "--\n" ;
            //cout << que.front()->val << endl;
            if (sp[i][0] != 'n')
            {
                ss.str("");
                ss.clear();
                ss << sp[i];
                ss >> temp;
                //cout << sp[i] << ">" <<  temp << endl;
                TreeNode *q = new TreeNode(temp);
                que.front()->left = q;
                que.push(q);
            }
            i++;
            if (sp[i][0] != 'n')
            {
                ss.str("");
                ss.clear();
                ss << sp[i];
                ss >> temp;
                //cout << sp[i] << ">" <<  temp << endl;
                TreeNode *q = new TreeNode(temp);
                que.front()->right = q;
                que.push(q);
            }
            i++;
            que.pop();
        }
        return root;
    }

private:
    void split(const string& str, const string& delim, vector<string> &res) {  
        //vector<string> res;  
        if("" == str) return;  
        //先将要切割的字符串从string类型转换为char*类型  
        char * strs = new char[str.length() + 1] ; //不要忘了  
        strcpy(strs, str.c_str());   

        char * d = new char[delim.length() + 1];  
        strcpy(d, delim.c_str());  

        char *p = strtok(strs, d);  
        while(p) {  
            string s = p; //分割得到的字符串转换为string类型  
            res.push_back(s); //存入结果数组  
            p = strtok(NULL, d);  
        }   
    }  
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```