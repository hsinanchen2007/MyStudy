### 解题思路
迭代、递归

### 代码

```cpp
class Solution {
public:

    //1、递归
    vector<int> preorder(Node* root) {
        vector<int> v;
        preorder_traversal(root, v);
        return v;
    }

    void preorder_traversal(Node* root, vector<int>& v) {
        if(root == nullptr)
            return;
        
        v.push_back(root->val);
        for(int i = 0; i < root->children.size(); ++i)
        {
            preorder_traversal(root->children.at(i), v);
        }
    }


    //2、迭代 使用栈 出栈时打印
    vector<int> preorder(Node* root) {
        vector<int> v;

        if(!root)
            return v;
       
        stack<Node*> s;
        s.push(root);

        while(!s.empty())
        {
            Node* node = s.top();
            s.pop();

            v.push_back(node->val);

            //从右到左入栈
            for(int i = node->children.size() - 1; i >= 0; --i)
            {
                if(root->children.at(i)) //非空才入栈
                    s.push(node->children.at(i));
            }
        }

        return v;
    }
};
```