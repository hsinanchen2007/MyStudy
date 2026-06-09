### 解题思路
思路比较简单，用一个vector记录每个字母出现的次数，如果是偶数次则回文长度加上偶数次数，若是奇数次则抛弃一个，最后在比较回文长度与字符串s的长度，如果小于字符串长度则说明还可以再加一个字符到回文中间，回文数＋1.

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>count(58);
        for(char c : s){
            count[c - 'A'] ++;
        }
        int Palindrome = 0;
        for( int i = 0; i < count.size(); i++){
            Palindrome += 2 * (count[i] / 2);
        }
        if(Palindrome < s.size()){
            Palindrome++;
        }
        return Palindrome;
    }
};
```