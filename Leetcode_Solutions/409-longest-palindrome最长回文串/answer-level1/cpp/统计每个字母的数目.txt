### 解题思路
遍历字符串，统计每个字符出现的次数，记录在数组Aa[52]中
然后遍历数组Aa[52]
如果某字母出现的次数为偶数，则统计；如果出现次数为奇数，则减一后统计，
同时将odd值置为1，表示某字符出现奇数次，最后将统计结果 +1

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int Aa[52] = {0},max = 0,odd = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                Aa[s[i]-'a']++;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                Aa[s[i]-'A'+26]++;
            }
        }

        for(int i=0;i<52;i++){
            if(Aa[i]%2 == 0){
                max += Aa[i];
            }
            else{
                odd = 1;
                max += Aa[i]-1;
            }
        }

        return max+odd;
    }
};
```