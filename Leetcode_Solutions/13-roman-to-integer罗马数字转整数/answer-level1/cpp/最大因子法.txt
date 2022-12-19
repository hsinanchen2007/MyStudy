### 解题思路
从大到小分别检测加法因子的个数，加到结果上

### 代码

```cpp
class Solution {
public:
    // 最大因子法，依次查找最大因子数量
    int romanToInt(string s) {
        int aa[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ss[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ind = 0, result = 0, i = 0;
        while(ind<13){
            string tmp = ss[ind];
            int j=0;
            while(i<s.size() && j<tmp.size() && s[i]==tmp[j]){
                ++i;
                ++j;
            }
            if(j<tmp.size()){
                ++ind;
                i -= j;
            }else{
                result += aa[ind];
            }
        }
        return result;
    }
};
```