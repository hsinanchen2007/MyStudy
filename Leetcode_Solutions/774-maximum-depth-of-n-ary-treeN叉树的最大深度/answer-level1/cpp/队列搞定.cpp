### 解题思路
队列广度优先遍历

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
    int maxDepth(Node* root) {
        queue<Node* > NodeQue;
        Node* curNode = NULL;
        if (root)
        {
            NodeQue.push(root);
        }
        //vector<vector<int>> levelRet;
        int level = 0;

        while (!NodeQue.empty())
        {
            int size = NodeQue.size();
            //levelRet.push_back(vector<int>(size,0));
            for (int i = 0; i < size; i++)
            {
                curNode = NodeQue.front();
                NodeQue.pop();
                //levelRet[level][i] = curNode->val;
                for (auto N : curNode->children)
                {
                    NodeQue.push(N);
                }
            }

            level++;
        }

        return level;
    }
};
```