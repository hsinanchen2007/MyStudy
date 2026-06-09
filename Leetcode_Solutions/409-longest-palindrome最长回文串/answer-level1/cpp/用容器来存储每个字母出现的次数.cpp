### 解题思路

1、用容器存字母和出现次数方便很多
2、len += (count[k]/2)*2 可以有效解决奇数次出现的字母统计问题
3、如果存在奇数次出现的字母加1
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int len=0,flag=0;
        vector<int> count(52,0); //存每个字母的出现次数
        for(auto c : s){
            if('z' >= c && c >= 'a') {
                count[c-'a']++;
            }
            if('Z' >= c&& c> = 'A') {
                count[c-'A'+26]++;
            }
        }
        for(int k = 0; k < 52; k++){
            len += (count[k]/2)*2;
            if(count[k] % 2 != 0) flag = 1;
        }
    return len+flag;
    }
};
```