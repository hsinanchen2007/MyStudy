### 解题思路
![image.png](https://pic.leetcode-cn.com/aee56c47cf560857e9eda039972018d7922b4e3db7e69a2df6a083f047836a58-image.png)

依次遍历字符串，遇到'['就进入递归，递归终止条件就是遇到了']'。
在解码"[]"中的字符串时：
    · 如果遇到的是字符，则将其和前面的连续一起保存起来；
    · 如果遍历到了数字，记录下来，这个就是后面"[]"括起来的子字符串需要重复的次数。       
    可能会出现"ab3[a]"这种情况，所以遇到数字之后要把之前保存的连续字符"ab"先记录到返回结果里面；
大概思路是这样，具体实现可以看代码。
### 代码

```cpp
class Solution {
public:
    int len;
    string s;
    string decodeString(string s) {
        len = s.size();
        this->s = s;
        int index = 0;
        string ans = helper(index);
        return ans;
    }

    string helper(int& index) {
        string ans;
        string temp; // 保存连续的字符
        string recusive; // 保存递归返回的结果
        int times = 0;
        while (index < len) {
            char c = s[index++];
            // 如果是字符，就将其和之前的字符一起保存下来
            if (isalpha(c)) {
                temp.push_back(c);
                continue;
            }
            // 如果是数字，可能需要先处理好之前保存的连续字符
            if (isdigit(c)) {
                if (!temp.empty()) {
                    ans += temp;
                    temp.clear();
                }
                times = times * 10 + (c - '0');
                continue;
            }
            // 遇到'['进入递归
            if (c == '[') {
                recusive = helper(index);
            }
            //  将'[]'中的解码结果重复times次
            for (; times > 0; times--) {
                ans += recusive;
            }
            // 遇到']'结束递归
            if (c == ']') {
                ans += temp;
                temp.clear();
                break;
            }
        }
        // 像"3[cd]ef"最后可能会有连续字符保存在temp中，需要处理好
        if (!temp.empty())
            ans += temp;
        return ans;
    }
};
```