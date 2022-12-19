### 代码

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool>visited1(n,false);
        vector<bool>visited2(n,false);
        unordered_set<int>parent;
        queue<int>q;
        if(leftChild[0] != -1 ||rightChild[0] != -1)
        {
            q.push(0);
            parent.insert(0);
        }
        while(!q.empty())
        {
            int root = q.front();
            q.pop();
            if(leftChild[root] != -1)
            {
                if(parent.count(leftChild[root]) != 0)
                {//子女指向双亲
                    return false;
                }
                q.push(leftChild[root]);
                parent.insert(leftChild[root]);
            }
            if(rightChild[root] != -1)
            {
                if(parent.count(rightChild[root]) != 0)
                {//子女指向双亲
                    return false;
                }
                q.push(rightChild[root]);
                parent.insert(rightChild[root]);
            }
        }
        return parent.size() == n; // 不等于说明有节点漏了,不在二叉树里
    }
};
```