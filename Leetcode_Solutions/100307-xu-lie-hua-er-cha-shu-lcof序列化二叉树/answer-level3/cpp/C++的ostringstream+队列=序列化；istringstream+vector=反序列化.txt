### 解题思路
利用ostringstream可以直接将数字变成字符串输出；利用istringstream可以实现类似python的split效果；反序列化的基本思路：vector中当前节点下标为i，其左子树为i+1，右子树为i+2

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
        ostringstream out;  //字符串输出流
        queue<TreeNode *> treeq;
        treeq.push(root);
        while(!treeq.empty())
        {
            TreeNode *frontNode = treeq.front();
            treeq.pop();  //出队
            if(frontNode)
            {
                out<<frontNode->val<<" ";  //这里会直接将整数val变成字符串
                treeq.push(frontNode->left);
                treeq.push(frontNode->right);
            }
            else
            {
                out<<"null"<<" ";
            }
        }
        return out.str();  //务必注意要返回string
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string strval;  //用于存储每个字符串
        vector<TreeNode *> treevec;
        //先构建单个节点，存入vector，最后再连接！！！
        while(input >> strval)  //这里相当于python的split
        {
            if(strval.size()==0)return nullptr;
            //strval不是"null"就是数字
            if(strval == "null")
            {
                treevec.push_back(nullptr);
            }
            else
            {
                treevec.push_back(new TreeNode(stoi(strval)));
            }
        }
        //现在开始连接这些节点
        int j = 1;  //表示左右子树的下标
        for(int i=0; i < treevec.size(); ++i)
        {
            if(treevec[i])
            {
                treevec[i]->left = treevec[j++];  //i的左子树为j
                treevec[i]->right = treevec[j++];  //i的右子树为j
            }
        }
        return treevec[0];  //返回根节点
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```