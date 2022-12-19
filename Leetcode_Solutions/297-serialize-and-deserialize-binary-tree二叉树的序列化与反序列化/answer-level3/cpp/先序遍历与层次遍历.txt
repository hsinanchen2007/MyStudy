### 解题思路
方法1
先序遍历与重建
效率较低
方法2
层次遍历与重建
执行用时 :32 ms, 在所有 cpp 提交中击败了98.77%的用户
内存消耗 :26.4 MB, 在所有 cpp 提交中击败了50.66%的用户
### 代码
方法1
```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(root==NULL) return "#!";
       string res=to_string(root->val)+"!";
       res+=serialize(root->left);
       res+=serialize(root->right);
       return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;
        while (getline(ss, item, '!')) 
            q.push(item);
        return helper(q);
    }
    TreeNode* helper(queue<string>& q)
    {
        string val = q.front();
        q.pop();
        if (val == "#")
            return NULL;
        TreeNode* head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
};
```

方法2
```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ret;
        queue<TreeNode*> que;
        que.push(root);
        int i;
        int k;
        while(!que.empty())
        {
            k=que.size();
            i=0;
            while(i<k)
            {
                TreeNode* node=que.front();
                que.pop();
                if(node==NULL)
                ret+="#!";
                else
                {
                    ret+=to_string(node->val)+"!";
                    que.push(node->left);
                    que.push(node->right);
                }
                i++;
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream ss(data);
        string item;
        queue<string> q;
        while (getline(ss, item, '!')) 
            q.push(item);
        return helper(q);
    }
    TreeNode* helper(queue<string>& q)
    {
        queue<TreeNode*> que;
        TreeNode* root=new TreeNode(stoi(q.front()));
        que.push(root);
        q.pop();
        int i;
        int k;
        while(!q.empty())
        {
            i=0;
            k=que.size();
            while(i<k)
            {
                TreeNode* node=que.front();
                que.pop();
                if(q.front()!="#")
                {
                    node->left=new TreeNode(stoi(q.front()));
                    que.push(node->left);
                    q.pop();
                }
                else
                {
                    node->left=NULL;
                    q.pop();
                }
                if(q.front()!="#")
                {
                    node->right=new TreeNode(stoi(q.front()));
                    que.push(node->right);
                    q.pop();
                }
                else
                {
                    node->right=NULL;
                    q.pop();
                }
                i++;
            }  
        }
        return root;
    }
};

```