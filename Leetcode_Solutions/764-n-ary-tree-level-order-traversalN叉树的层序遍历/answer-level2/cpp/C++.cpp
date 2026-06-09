### 解题思路
与二叉树相比 就是把非空的左、右子树入队，改为遍历所有非空子树入队

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

    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> vv;

        if (root == nullptr)
            return vv;

        queue<Node*> q;
        q.push(root);

        Node* last = root; //本层最后一个节点
        Node* nlast = nullptr; //下一层最后一个节点

        vector<int> v;

        while (!q.empty())
        {
            Node* node = q.front();
            q.pop();

            v.push_back(node->val);

            for(int i = 0; i < node->children.size(); ++i)
            {
                if (node->children.at(i))
                {
                    q.push(node->children.at(i));
                    nlast = node->children.at(i);
                }
            }

            if (node == last)
            {
                //换行
                last = nlast;

                vv.push_back(v);
                v.clear();
            }
        }
        return vv;
    }
};
```