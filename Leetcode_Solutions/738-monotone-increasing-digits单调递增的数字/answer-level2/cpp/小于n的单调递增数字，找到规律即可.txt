### 解题思路
规律：
从倒数第二个数字开始遍历，若s[i] > s[i+1]，那么此时是逆序的，对s[i]减1，然后把s[i]后所有数字变成9即可
若s[i] <= s[i+1]，此时是有序的，不用管

### 代码

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s(to_string(N));
        for(int i = s.size()-2;i>=0;--i){
            if(s[i] != '+' && s[i] != '-' && s[i] > s[i+1]){
                --s[i];
                for(int j = i+1;j < s.size();++j)
                    s[j] = '9';
            }
        }
        return atoi(s.c_str());
    }
};
```