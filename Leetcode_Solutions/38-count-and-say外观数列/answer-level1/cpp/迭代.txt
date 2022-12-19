### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了87.65% 的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了26.85%的用户

### 代码

```cpp
class Solution {
public:
    string countAndSayCore(string s) {
    	string s_parsed;
    	size_t ind = 0;
    	while(ind < s.size())
    	{
    		int times = 1;
    		while(s[ind] == s[ind+1]){
    			times++;
    			ind++;
    		}
    		s_parsed += to_string(times);
    		s_parsed += s[ind];
    		ind++;
    	}
    	return s_parsed;
    }
    string countAndSay(int n) {
    	int i = 1;
    	string s_parsed = to_string(1);
    	while(i < n){
    		s_parsed = countAndSayCore(s_parsed);
    		i++;
    	}
    	return s_parsed;
    }
};
```