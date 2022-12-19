### 解题思路
十分简单的字符统计,分别统计大写、小写字母数量以及是否首字母大写,根据单词大写使用正确的条件返回结果.

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int big = 0, small = 0;
        bool isFirst = false;
        if(word[0] >= 65 && word[0] <= 90) isFirst = true;
        for(int i = 0; i < n; i++){
            if(word[i] >= 65 && word[i] <= 90) big++;
            else small++;
        }
        if(big == n) return true;
        else if(small == n) return true;
        else if(isFirst && small == n - 1) return true;
        else return false;
    }
};
```