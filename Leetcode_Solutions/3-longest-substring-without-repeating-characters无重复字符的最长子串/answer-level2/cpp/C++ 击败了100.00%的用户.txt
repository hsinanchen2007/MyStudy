### 解题思路

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户

直接使用C风格对const char*的遍历，O(N-1)即可完成。不要使用set，不添加额外的string对象，节省了内存；

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) {
            return s.size();
        }

        int result = 0;
        const char* str = s.c_str();
        
        const char* sub = str;
        int subLen = 1;
        
        for (size_t i = 1; i < s.size(); ++i) {
            char c = str[i];
            const char* s = strchr(sub, c);
            
            if (s == NULL || s >= (sub + subLen)) {
                subLen ++;
                result = subLen > result ? subLen : result;
            } else  {
                result = subLen > result ? subLen : result;
                sub = s + 1;
                subLen = str + i - s;
            }
        }
        return result;  
    }
};
```