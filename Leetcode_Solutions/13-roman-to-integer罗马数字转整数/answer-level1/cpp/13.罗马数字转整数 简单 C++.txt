### 运用知识点：哈希表，string
本题为简单题，一开始反而想得复杂了，想用栈来做（因为这是处理字符串还有表达式的常用方法吧？？）其实罗马数字转整数也蕴含了表达式的意味，只不过仅需通过比较前后两个罗马数字大小即可以得到该数字前的“算术符号”。
“只有以下六种情况......”这段话也将我引导了去错的方向，觉得要将其视为特殊情况处理，其实本题输入的必定是正确的罗马数字，所以不用考虑“小的罗马数字在左边但又不在这六种情况的错误情况”。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanMap = {{'I', 1}, {'V',5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            int first = romanMap[s[i]];
            int next = romanMap[s[i+1]];
            if(first < next) {
                result -= first;
            } else {
                result += first;
            }
        }
        result += romanMap[s[s.length()-1]];
        return result;
    }
};
```