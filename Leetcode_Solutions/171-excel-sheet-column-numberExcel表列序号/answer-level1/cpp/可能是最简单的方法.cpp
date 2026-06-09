一下子就理解了，最后一个字母，就是26的0次方乘以他代表的数字，倒数第二个字母就是26的一次方乘以他代表的数字，以此类推加起来，一个for循环就搞定！少见的那么简单理解的题目
```
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = s.size() - 1, count = 0; i >= 0; --i, ++count)
            result += (s[i] - 'A' + 1) * pow(26, count);
        return result;
    }
};
```