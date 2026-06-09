### 解题思路
该题最初的想法是这样，poped是个队列，pushed的每个元素入栈，当top元素与队列的头部元素相等的时候就弹出栈。。不相等继续入栈，若全部元素入栈之后，
并不能遍历完队列则返回false;队列可以由vector代替，队列元素没有遍历完相当于栈中有元素。
### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }

        std::stack<int> st;
        int j = 0;
        for(auto d : pushed){
            st.push(d);

            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};
```