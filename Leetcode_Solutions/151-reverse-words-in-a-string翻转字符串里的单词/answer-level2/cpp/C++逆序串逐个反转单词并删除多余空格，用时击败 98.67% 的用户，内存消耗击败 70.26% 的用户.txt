### 解题思路

整体思路 : 
1. 删除首尾空格后构造一个逆序新串
2. 遍历新串反转每个单词同时删除多余空格

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;

        // 找到第一个不是空格的位置
        while (left <= right && isspace(s[left]))
            ++left;
        // 找到最后一个不是空格的位置
        while (right >= 0 && isspace(s[right]))
            --right;
        
        // s中只含空格
        if (right < left)
            return string("");
        
        // 反向构造新的string  
        string res(s.rbegin() + (s.size() - right - 1), s.rbegin() + (s.size() - left));

        // 反转单词并删除多余空格
        auto iter = res.begin(), pre = iter;
        while (true) {
            // pre记录单词的起始位置
            if (iter != res.end() && *iter != ' ')
                pre = iter;
            // iter指向当前单词的下一个位置
            while (iter != res.end() && *iter != ' ')
                ++iter;
            // 反转
            reverse(pre, iter);
            // 最后一个单词完成反转后退出
            if (iter == res.end())
                break;

            // 当前iter指向空格 
            pre = ++iter;
            // 若pre指向空格 说明含多余空格
            if (*pre == ' ') {
                // iter指向此后第一个不是空格的位置
                while (iter != res.end() && *iter == ' ')
                    ++iter;
                // 删除多余空格 pre指向iter原来指向的字符(此时iter已失效)
                pre = res.erase(pre, iter);
                // 从新的单词开始
                iter = pre;
            }
        }
        return res;
    }
};
```