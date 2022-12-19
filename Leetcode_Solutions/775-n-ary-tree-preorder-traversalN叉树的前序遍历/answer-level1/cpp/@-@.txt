### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> nums;

        if (root == nullptr)
        {
            return nums;
        }

        stack<Node*> ptrs;
        ptrs.push(root);

        while (!ptrs.empty())
        {
            auto ptr = ptrs.top();
            ptrs.pop();

            nums.push_back(ptr->val);
            for (auto it = ptr->children.rbegin(); it != ptr->children.rend(); it++)
            {
                if (*it != nullptr)
                {
                    ptrs.push(*it);
                }
            }
        }

        return nums;
    }
};
```