设置一个栈来模拟
先入栈一个push数组的元素
然后不断的将栈顶元素和poped数组的元素比较，若是相同，则出栈

```
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
          stack<int> st;
          int n=pushed.size();
          int j=0;
          for(int i=0;i<n;i++)
          {
              st.push(pushed[i]);
              while(!st.empty()&&j<n&&st.top()==popped[j])
              {
                  st.pop();
                  j++;
              }
          }
          return st.empty();
    }
};
```


