### 解题思路
此处撰写解题思路
![589.jpg](https://pic.leetcode-cn.com/6bb01ef4355b623f485b5703df6b6db89a0ebbbcb6ebd99567cbcaa61643b63e-589.jpg)

### 代码

```cpp
//同样使用迭代法，与后序相比，只是vector push_back的地方不同
#include <stack>
#include <utility>
#include <vector>
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<pair<Node*, int>> loopStack;
        vector<int> resVec;
        if(NULL == root)
        {
            return resVec;
        }
        int curPointer = 0;
        Node* curT = root;
        resVec.push_back(curT->val);
        while(1)
        {
            if(curT->children.size() <= curPointer)
            {
                if(curT == root)
                {
                    break;
                }
                curT = loopStack.top().first;
                curPointer = loopStack.top().second;
                loopStack.pop();
            }
            else
            {
                loopStack.push(pair<Node*, int>(curT, curPointer+1));
                curT = curT->children[curPointer];
                curPointer = 0;
                resVec.push_back(curT->val);
            }
        }
        return resVec;
    }
};










```