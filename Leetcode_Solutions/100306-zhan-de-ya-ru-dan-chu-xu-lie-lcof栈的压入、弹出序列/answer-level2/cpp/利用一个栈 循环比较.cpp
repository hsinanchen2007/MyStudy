### 解题思路
每一次比较栈顶元素与popped当前元素是否相同，不同就将pushed元素压入栈中。

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=0&&popped.size()==0) return false;
        stack<int> pushStack;
        int i=0,j=0;
        while(i<pushed.size()||!pushStack.empty()){
            if(!pushStack.empty()&&popped[j]==pushStack.top()){
                pushStack.pop();
                j++;
            }
            else{
                if(i>=pushed.size()) break;
                pushStack.push(pushed[i]);
                i++;
            }
        }
        
        return j==popped.size();
    }
};
```