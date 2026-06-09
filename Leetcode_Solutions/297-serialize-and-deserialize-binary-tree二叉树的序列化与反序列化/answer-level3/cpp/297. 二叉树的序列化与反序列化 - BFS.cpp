思路不难，需要处理字符串的各种情况，细节见代码：

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans("[");
        bool flag = false;  // 处理逗号

        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();

            if(flag) ans.append(",");
            else flag = true;

            if(cur == nullptr)
            {
                ans.append("null");
            }
            else
            {
                ans.append(to_string(cur->val));
            }

            if(cur)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        ans.append("]");
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode**> q; // 注意：这里要传二级指针
        TreeNode* root = nullptr;
        q.push(&root);

        int i = 1;           // 从下标 1 开始，跳过'['
        int num = 0;         // 保存当前节点的数字
        bool isNull = false; // 处理空结点
        bool isNeg = false;  // 处理负数
        while(i < data.size())
        {
            if(data[i] == ',' || data[i] == ']')
            {
                TreeNode** cur = q.front();
                q.pop();

                if(!isNull)
                {
                    if(isNeg) num = -num;
                    *cur = new TreeNode(num);
                    q.push(&(*cur)->left);
                    q.push(&(*cur)->right);
                }

                num = 0;
                isNull = false;
                isNeg = false;
            }
            else if(isdigit(data[i]))
            {
                num = num * 10 + data[i] - '0';
            }
            else if(data[i] == '-')
            {
                isNeg = true;
            }
            else
            {
                isNull = true;
            }

            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
