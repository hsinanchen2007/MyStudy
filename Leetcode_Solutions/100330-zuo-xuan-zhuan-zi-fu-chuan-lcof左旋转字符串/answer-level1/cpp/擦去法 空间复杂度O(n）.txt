### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
    	string s_head = s;//设立辅助String
    	s_head.erase(s_head.begin()+n, s_head.end());////擦去后面部分的字符串
    	s += s_head;//拼接
    	s.erase(s.begin(), s.begin()+n);//擦去前面部分的字符串
    	return s;
    }
};

```