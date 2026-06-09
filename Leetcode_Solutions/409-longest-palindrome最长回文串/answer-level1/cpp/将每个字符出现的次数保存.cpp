### 解题思路
将每个字符出现的次数保存
### 代码
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if( s.size()== 0) return 0;
        vector<int>ch(128,0);
        for(auto c : s)
            ch[c]++;
        bool flag =  false;
        int num = 0;
        for(int i = 0; i < 128; i++){
            if(ch[i] >= 2) {
                num += (ch[i] / 2 ) * 2; 
            }
        }
        if(num < s.size() && ( num%2 == 0 ) )
            num++;
        return num;
    }
};
```