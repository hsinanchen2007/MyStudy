### 解题思路
设立一个栈st，将pushed入栈，如果st.top==popped[j]，出栈。如果不相等，继续入栈。
检查最后出栈了几次，是不是和popped的长度一样。
注意：1、不是if是while，出栈不是一个，是一堆。
2、要检查st.size()是否为0.而且判断是否为0要写在st.top()之前！！！否则会报错。

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //if(pushed.size()==0&&popped.size()!=0) return false;
        //if(popped.empty()) return true;
        stack<int> st;//建立辅助栈
        int j=0;
        int n=popped.size();
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            while(!st.empty()&&st.top() == popped[j] )//这里不是if 是while！！
            //while(st.top() == popped[j]&&j<n&&!st.empty())
            {
                st.pop();
                j++;
            }
        }
        if(j==popped.size()) return true;
        else return false;
        //return st.empty();

    }
};


```