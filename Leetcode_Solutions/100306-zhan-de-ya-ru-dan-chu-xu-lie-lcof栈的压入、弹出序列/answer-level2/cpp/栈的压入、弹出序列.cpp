### 解题思路

使用一个栈模拟popped的行为
首先在pushed的入栈顺序里寻找popped出栈顺序的位置
比如 pushed:   1 2 3 4 5 6 7
     popped:   3 2 6 7 5 4 1
st中  1 2 3 以入栈
按顺序出 3
      出 2
当popped 为 6时,栈顶元素与6不相同
在从pushed中入4 5 6
此时栈中元素为 1 4 5 6按此顺序出栈


### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() <= 0 && popped.size() <=0)
            return true;
        if(pushed.size() <= 0 || popped.size() <=0){
            return false;
        }
        stack<int> st;
        int cut = 0;
        bool ret  = false;

        for(int i = 0; i < popped.size(); i++){
            ret  = false;
            if(!st.empty() && st.top() == popped[i]){
                //cout<< st.top();
                ret = true;
                st.pop();
            }
            else {
                while(cut < pushed.size() && pushed[cut] != popped[i]){
                    st.push(pushed[cut++]);
                }
                if(cut < pushed.size() && pushed[cut] == popped[i]){
                    st.push(pushed[cut++]);
                }
                if(!st.empty() && st.top() == popped[i]){
                     //cout<< st.top();
                      ret = true;
                    st.pop();
                }
            }
            if(!ret){
                return false;
            }
        }
        return ret;

    }
};
```