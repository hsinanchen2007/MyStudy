### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        for(int i=0;i<s.length();){
            string t;
            while(s[i]==' ')i++;
            while(i<s.length()&&s[i]!=' '){
                t+=s[i];
                i++;
            }
            ans.push_back(t);
        }
        string ans1;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]!=""){
                ans1+=ans[i];
                if(i!=0)
                ans1+=' ';
            }
        }
        return ans1;
    }
};
```