### 解题思路
用两个指针，遍历找到每个单词的首位，然后翻转该单词，翻转后继续寻找，直到遍历完毕。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int start= 0; // 用来指需要翻转单词的首位
        int end = 0;  // 用来指需要翻转单词的末位
        while(start < size) //遍历
        {
            while(s[start] ==' ' && start < size) start++; //找到不为空格的单词首位

            end = start;// 直接从非空单词首位开始找
            while(s[end] != ' ' && end < size) end++; //找到不为空格的单词末位

            reverse(s.begin() + start, s.begin() + end); //翻转当前单词

            start = end; // 开始找下一个单词的其实位置更新
        }

        return s;
    }
};
```

### 执行结果
![微信截图_20200323235301.png](https://pic.leetcode-cn.com/45dd5f03880b02e1b2c7f1085988af1c810a3633c491217b9fcb7ce346fc6cb3-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200323235301.png)
