### 解题思路
参考liweiwei的解题分析及Java代码，改写了C++版本。
首先建立基本单位的对应关系，
1000→M
**900 →CM**
500 →D
**400 →CD**
100 →C
**90  →XC**
50  →L
**40  →XL**
10  →X
**9   →IX**
5   →V
**4   →IV**
1   →I
其中，黑体注明的不是显式建立的，包括在题目的特殊条件中。此时，仅看题目的特殊情况，很容易被误导思路，让人下意识以为这些情况需要分开讨论，其实不然，所有情况均是可以放在一起的。
### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roma[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int index = 0;
        string str = "";
        while(index < 13){
            while(num >= nums[index]){
                num -= nums[index];
                str.append(roma[index]);
            }
            index++;
        }
        return str;
    }
};
```