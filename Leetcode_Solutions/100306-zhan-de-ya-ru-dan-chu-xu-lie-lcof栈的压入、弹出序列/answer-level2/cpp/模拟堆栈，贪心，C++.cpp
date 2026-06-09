### 解题思路
模拟堆栈。将push数组一个个推进来，每次判断当前栈顶是不是为pop数组里面最左端的元素，否则将pop数组指针向右移，直到两者不相等为止。
### 代码

```cpp
class Solution {
public:
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        for(int i=0,j=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(st.size()!=0&&st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        if(st.size()==0)return true;
        return false;
    }
};
```