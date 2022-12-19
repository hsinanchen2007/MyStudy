### 解题思路
此处撰写解题思路

### 代码

```cpp
#include <utility>
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<pair<Node*, int>> loopStack;
        vector<int> resVec;

        Node* curT = root;
        int curPointer = 0;
        if(NULL == curT)
        {
            return resVec;
        }

        while(1)
        {
            //该节点遍历到头
            if(curT->children.size() <= curPointer)
            {
                //该节点已经失去利用价值，所有儿子都被榨干
                //该输出了
                resVec.push_back(curT->val);
                if(curT == root)
                {
                    break;
                }
                //新的出栈
                curT = loopStack.top().first;
                curPointer = loopStack.top().second;
                loopStack.pop();
            }
            //该节点还有可用孩子
            else
            {
                //否则curPointer移动，该节点重新入loopStack
                loopStack.push(pair<Node*,int>(curT,curPointer+1));
                //新的curT即将产生
                curT = curT->children[curPointer];
                curPointer = 0;
            }
        }
        return resVec;
    }
};







```