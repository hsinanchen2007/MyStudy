### 解题思路
见代码

### 代码

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
    	stack<string> st;
    	int len = S.size();

    	for (int i = 0; i < len; ++i) {
    		if (S[i] == '(') st.push("(");
    		else {
    			int tmp;
    			if (st.top() == "(") {
    				tmp = 1;
    			}
    			else {
    				tmp = atoi(st.top().c_str()) * 2;
                    st.pop();
    			}
    			st.pop();
    			while (!st.empty() && st.top() != "(") {
   					tmp += atoi(st.top().c_str());
   					st.pop();
   				}
   				st.push(to_string(tmp));
    		}
    	}
    	return atoi(st.top().c_str());
    }
};
```