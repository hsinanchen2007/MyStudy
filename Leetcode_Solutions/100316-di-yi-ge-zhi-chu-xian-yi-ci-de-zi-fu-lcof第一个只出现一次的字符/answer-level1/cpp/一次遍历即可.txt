### 解题思路
遍历字符串s的第i个字符时，
求出字符s[i]在s中第一次出现的下标first
求出字符s[i]在s中最后一次出现的下标last

如果第一次出现的下标first和最后一次出现的下标last相同，就表示，这个字符在整个字符中只出现一次

![图片.png](https://pic.leetcode-cn.com/37b3497769bed5afe1943a2eb5f921ce780008040a4676d7655cc98ff2abe2ae-%E5%9B%BE%E7%89%87.png)



### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        for(int i = 0; i < s.size() ; i++){
            int first=s.find(s[i]);
            int last=s.rfind(s[i]);
            if(first==last)return s[first];
        }
        return ' ';
    }
};
```