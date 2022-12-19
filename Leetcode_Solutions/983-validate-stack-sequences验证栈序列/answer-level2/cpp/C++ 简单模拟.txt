```
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_index=0, pop_index=0;
        int len=pushed.size();
        stack<int> Stack;
        while(pop_index<len) {
            while(push_index<len&&(Stack.empty()||Stack.top()!=popped[pop_index])) {
                Stack.push(pushed[push_index++]);
            }
            if(Stack.top()!=popped[pop_index]) {
                return false;
            }
            Stack.pop();
            pop_index++;
        }
        return pop_index>=len;
    }
};
```
