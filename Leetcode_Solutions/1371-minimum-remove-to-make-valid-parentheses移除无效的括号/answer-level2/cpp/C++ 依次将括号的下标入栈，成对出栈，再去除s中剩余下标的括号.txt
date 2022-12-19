### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<int> st;
		for (int i = 0; i < s.size(); ++i){
			if (!st.empty()){
                if(s[st.top()] == '(' && s[i] == ')'){
                    st.pop();
                    continue;
                }              
			}
			if(s[i] == '('||s[i] == ')')st.push(i);
		}	
		while(!st.empty()){
            s.erase(s.begin()+st.top());
            st.pop();
        }
		return s;

	}
};
```