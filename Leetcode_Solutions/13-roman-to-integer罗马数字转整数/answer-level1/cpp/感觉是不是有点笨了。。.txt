### 解题思路
先用map存一下对应关系，再从末尾开始计算这一位是需要加到结果里还是减到结果里

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> RomanMap;
        RomanMap['I'] = 1;
        RomanMap['V'] = 5;
        RomanMap['X'] = 10;
        RomanMap['L'] = 50;
        RomanMap['C'] = 100;
        RomanMap['D'] = 500;
        RomanMap['M'] = 1000;
        int IntResult = 0;
        int flag = 0;
        for(int i = s.size() - 1; i > 0 ; --i) {
            if(flag == 0) {
                IntResult = IntResult + RomanMap[s[i]]; 
                std::cout << "IntResult: +" << RomanMap[s[i]] << endl;
            } else {
                IntResult = IntResult - RomanMap[s[i]];
                std::cout << "IntResult: -" << RomanMap[s[i]] << endl;
            }
            if(RomanMap[s[i]] <= RomanMap[s[i - 1]]) {
                flag = 0;
            } else {
                flag = 1;
            }
        }            
        if(flag == 0) {
                IntResult = IntResult + RomanMap[s[0]]; 
                std::cout << "IntResult: +" << RomanMap[s[0]] << endl;
        } else {
                IntResult = IntResult - RomanMap[s[0]];
                std::cout << "IntResult: -" << RomanMap[s[0]] << endl;
        }
        return IntResult;
    }
};
```