### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了80.55% 的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了8.51%的用户

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
    	int ret = 0;
    	int ind = 0;
    	while(s.size()){
    		ret += (s[s.size()-1] - 'A' + 1)* pow(26, ind);
    		ind++;
    		s.erase(s.size()-1);
    	}
    	return ret;
    }
};
```