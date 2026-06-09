### 代码

```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int s1 = (int)word.size();
        int s2 = (int)abbr.size();
        if (s1 == 0 && s2 == 0) return true;
        if (s1 == 0) return false;
        
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int carry = 1;
        while (i < s1 && j < s2) {
            if (isdigit(abbr[j])) {
                sum = sum * carry + abbr[j] - '0';
                //sum 已经 超过了 s1剩余的长度了
                if (sum > s1 - i) return false;
                //"a"  "01"
                if (sum == 0) return false;
                carry *= 10;
                j++;
                continue;
            }
            // 判断sum
            if (sum > 0) {
                while (sum >= 1){
                    i++;
                    sum--;
                }
                carry = 1;
                continue;
            }
            if (word[i] == abbr[j]) {
                i++; j++;
                continue;
            }
            //不是数字 也不等于
            return false;
        }
        return i + sum == s1 && j == s2;
    }
};
```