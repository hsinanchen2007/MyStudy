### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int res=0;
        int flag=0;
        map<char,int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }

        for(auto it=map.begin();it!=map.end();it++){
            if(it->second%2==0) res+=it->second;
            else {
                res+=it->second-1;
                flag=1;
            }
        }

        res+=flag;
        return res;
    }
};
```