### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了98.61% 的用户
内存消耗 :10.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
    	string s_head = s;
    	s_head.erase(s_head.begin()+n, s_head.end());
    	s += s_head;
    	s.erase(s.begin(), s.begin()+n);
    	return s;
    }
};
```