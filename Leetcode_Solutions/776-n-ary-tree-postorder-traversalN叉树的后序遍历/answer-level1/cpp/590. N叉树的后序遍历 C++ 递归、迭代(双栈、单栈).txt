### 解题思路


### 代码

```cpp

class Solution {
public:

    //递归
    vector<int> postorder(Node* root) {
        vector<int> v;

        postorder(root, v);

        return v;
    }

    void postorder(Node* root, vector<int>& v) {
        if(root == nullptr)
            return;
        
        for(int i = 0; i < root->children.size(); ++i)
        {
            postorder(root->children.at(i), v);
        }
        v.push_back(root->val);
    }

    //迭代 使用双栈
    vector<int> postorder(Node* root)
    {
        vector<int> v;

        if (root == nullptr)
            return v;

        stack<Node*> s1;
        s1.push(root);

        stack<Node*> s2;

        while (!s1.empty())
        {
            Node* node = s1.top();
            s1.pop();

            s2.push(node);

            for(int i = 0; i < node->children.size(); ++i)
            {
                if(node->children.at(i))
                    s1.push(node->children.at(i));
            }
        }

        while (!s2.empty())
        {
            Node* node = s2.top();
            s2.pop();
            v.push_back(node->val);
        }

        return v;
    }

    //迭代 使用一个栈  与N叉树的前序遍历类似， 但子树的入栈顺序为从左到右
    vector<int> postorder(Node* root) {
        vector<int> v;

        if(!root)
            return v;
       
        stack<Node*> s;
        s.push(root);

        while(!s.empty())
        {
            Node* node = s.top();
            v.push_back(node->val);
            s.pop();

            //从左到右入栈
            for(int i = 0 ; i < node->children.size(); ++i)
            {
                if(node->children.at(i)) //非空结点才入栈
                    s.push(node->children.at(i));
            }
        }

        //将v反转
        reverse(v.begin(), v.end());

        return v;
    }
};
```