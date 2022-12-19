```cpp
class Solution {
public:
    string intToRoman(int num) {
        assert(num > 0 && num < 4000);
        string ret;
        pair<int, string> p[] { 
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        int n = sizeof(p) / sizeof(p[0]);
        while(n > 0){
            while(num >= p[n - 1].first){
                ret += p[n - 1].second;
                num -= p[n - 1].first;
            }
            --n;
        }
        
        return ret;
    }
};
```