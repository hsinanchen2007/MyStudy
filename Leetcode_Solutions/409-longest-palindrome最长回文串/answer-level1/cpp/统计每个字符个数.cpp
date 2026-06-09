### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        int res=0;
        for(auto m:mp){
            if(m.second%2==0){
                res+=m.second;
            }
            else{
                res+=(m.second-1);
            }
        }
        if(res<s.size()){
            res++;
        }
        return res;

    }
};
```