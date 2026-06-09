### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了83.81% 的用户
内存消耗 :11 MB, 在所有 C++ 提交中击败了40.13%的用户

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
    	if(!s.size()) return s;
    	s += " ";
    	string s_reverse;
    	vector<string> v_s;
    	string s_sub;
    	for(size_t i=0;i<s.size();++i){
    		char ch = s[i];
    		if(ch != ' ')
    		{
    			s_sub += ch;
    		}
    		else{
    			if(s_sub.size())
    				v_s.push_back(s_sub);

    			s_sub.clear();
    		}
    	}
    	for(auto iter = v_s.rbegin(); iter != v_s.rend(); ++iter){
    		s_reverse += *iter;
    		s_reverse += " ";
    	}
    	s_reverse.erase(s_reverse.end()-1);

    	return s_reverse;
    }
};
```