### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> ::iterator it;    
        for(int i = 0;i<s.length();i++){
            ++mp[s[i]];
        }
        int sum=0;
        bool cnt = false;
        for(it=mp.begin();it!=mp.end();it++){
            sum+=(it->second/2*2);
            if(!cnt&&it->second%2==1){
                cnt = true;
            }
        }
        if(cnt){
            sum++;
        }
        return sum;
    }
};
```