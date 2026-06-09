### 解题思路
执行用时 :48 ms, 在所有 C++ 提交中击败了81.08% 的用户
内存消耗 :17.3 MB, 在所有 C++ 提交中击败了13.53%的用户

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
    	size_t start_ind = 0;
    	for(size_t i=0;i<s.size();++i){
    		char ch = s[i];
    		auto ind = std::find(t.begin() + start_ind, t.end(), ch);
    		if(ind == t.end()) return false;
    		start_ind = ind - t.begin() + 1;
    	}
    	return true;
    }
};
```