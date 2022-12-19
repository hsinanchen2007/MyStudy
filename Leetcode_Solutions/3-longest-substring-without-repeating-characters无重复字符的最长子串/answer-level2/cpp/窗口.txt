### 解题思路
此处撰写解题思路
用滑动窗口，遍历字符串，判断新加入的字符在窗口中是否存在
    存在则删除窗口的begin()到存在字符+1范围内的子串
更新子串的最大值
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> win;
        int maxlen = 0;
        vector<char>::iterator result;
        for (int i = 0; i < s.size(); i++) {
            //出现过
            if ((result = find(win.begin(), win.end(), s[i])) != win.end()) {            
                win.erase(win.begin(), result+1);
            }
            win.push_back(s[i]);
            if (maxlen < win.size()) {
                maxlen = win.size();
            }
        }
        return maxlen;
    }
};
```