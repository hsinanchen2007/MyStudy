### 解题思路
模拟入栈出栈过程

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size())
            return false;
        int i=0;
        int j=0;
        stack<int> temp;
        while(i<pushed.size() && j<popped.size()){
            if(temp.empty()){
                temp.push(pushed[i]);
                ++i;
                continue;
            }
            if(popped[j]==temp.top()){
                temp.pop();
                ++j;
                continue;
            }
            while(i<pushed.size() && pushed[i]!=popped[j]){
                temp.push(pushed[i]);
                ++i;
            }
            if(i==pushed.size())//弹出一个非栈顶元素
                return false;
            ++i;
            ++j;
        }
        for(;j<popped.size();++j){
            if(temp.empty() || popped[j]!=temp.top())
                return false;
                temp.pop();
        } 
        if(!temp.empty())
            return false;
        return true;
    }
};
```