### 解题思路
比官方代码差多了。但思路一样吧好像。

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int to_push = pushed.size();
        stack<int> mystack;
        int pop_index = 0;
        while(to_push > 0){
            if(mystack.empty() || mystack.top() != popped[pop_index]){
                mystack.push(pushed[pushed.size() - to_push]);
                to_push -- ;
            }else if(mystack.top() == popped[pop_index] &&pop_index < popped.size() ){
                mystack.pop();
                pop_index++;
            }
        }
        while(!mystack.empty() && pop_index < popped.size()){
            if(mystack.top() != popped[pop_index])
            return false;
            else {
                mystack.pop();
                pop_index ++;
            }
        }

        return true;
    }
};
```