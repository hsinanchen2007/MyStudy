### 解题思路
使用unordered_set减少代码量，注意在swap函数后还需要++i和--j
### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels {'a','e','i','o','u','A','E','I','O','U'};
        int i = 0;
        int j = size(s)-1;
        while(i<j){
            if(vowels.count(s[i])==0){
                
                ++i;
                continue;
            }
            if(vowels.count(s[j])==0){
                
                --j;
                continue;
            }

            swap(s[i],s[j]);
            ++i;
            --j;

        }
        return s;
    }
};
```