### 解题思路
分析：可以先用map统计一遍字符个数，再顺序遍历字符，如果某个字符的value为1就说明
该字符是第一个唯一字符

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int > m;
        // 统计字符个数 
        for (int i = 0; i < s.size(); i++) m[s[i]]++;
        for (int i = 0; i < s.size(); i++) {
        	// 找出第一个不重复的字符 
        	if (m[s[i]] == 1) return i;
		}
		// 字符全都重复了的情况 
		return -1;
    }
}; 
```