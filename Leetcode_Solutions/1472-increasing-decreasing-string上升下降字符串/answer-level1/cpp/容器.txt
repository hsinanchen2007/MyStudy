### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string sortString(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        string ans;
        while(ans.size()<s.size()){
            for(int i=0;i<26;i++){
                if(m[i+'a']!=0){
                    ans+=i+'a';
                    m[i+'a']--;
                }
                if(ans.size()==s.size())break;
            }
            if(ans.size()==s.size())break;
            for(int i=25;i>=0;i--){
                if(m[i+'a']!=0){
                    ans+=i+'a';
                    m[i+'a']--;
                }
                if(ans.size()==s.size())break;
            }
        }
        return ans;
    }
};
```