### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int lastvalid=-1,start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') s[++lastvalid]=s[i];
            if(s[i]==' ' && lastvalid!=-1 && s[i+1]!=' ' && s[i+1] !='\0'){
                s[++lastvalid]=s[i];
                reverse(s.begin()+start,s.begin()+lastvalid);
                start=lastvalid+1;
            }
            if(i==s.size()-1) reverse(s.begin()+start,s.begin()+lastvalid+1);
        }
        if(lastvalid==-1)  return "";
        return s.substr(0,lastvalid+1);
    }
};
```