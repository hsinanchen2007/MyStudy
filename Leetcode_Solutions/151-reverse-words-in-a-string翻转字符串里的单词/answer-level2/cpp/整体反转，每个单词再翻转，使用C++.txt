### 解题思路
这次代码写的太懒了，又臭又长，但打败的用户还挺多。

总的思路是先把空格处理了，就在源字符串的基础上处理，删除多余的空格。

然后就是写一个reverseString函数，专门处理字符翻转。
然后在主流程里，先翻转所有的字符，然后再针对其中的word单独翻转，就得到了答案。

有时间我还得把代码优化一下，看起来太冗长。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int pos_left = 0;
        int pos_right = 0;

        for (pos_right = 0, pos_left = 0; pos_right < s.size(); ++pos_right) {
            if ((pos_right - 1 >= 0 && s[pos_right] == s[pos_right - 1] && s[pos_right] == ' ')
                || (pos_right == 0 && s[pos_right] == ' ')) {
                continue;
            }

            if (pos_right != pos_left) {
                s[pos_left] = s[pos_right];
            }

            ++ pos_left;
        }

        if (pos_left - 1 >= 0 && s[pos_left - 1] == ' ') {
            -- pos_left;
        }
        s.resize(pos_left);

        this->reverseString(s, 0, s.size() - 1);

        pos_right = pos_left = 0;
        while (pos_right < s.size()) {
            while (pos_right < s.size() && s[pos_right] == ' ') ++ pos_right;
            pos_left = pos_right;
            while (pos_right < s.size() && s[pos_right] != ' ') ++ pos_right;
            this->reverseString(s, pos_left, pos_right - 1);
        }
        return s;
    }

    void reverseString(string& s, int start, int end) {
        while (start < end) {
            std::swap(s[start], s[end]);
            start += 1;
            end -= 1;
        }
    }
};
```

![微信图片_20200102174108.png](https://pic.leetcode-cn.com/8d8102595fbb5452a7f0905f3ce402fbdac113b104fbe7b79b1c3c7d100e66ab-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200102174108.png)
