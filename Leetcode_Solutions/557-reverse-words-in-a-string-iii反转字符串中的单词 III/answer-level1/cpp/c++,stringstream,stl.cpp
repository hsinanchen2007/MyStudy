### 解题思路
用reverse函数和stringstream方便

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(!s.size())return s;
        stringstream ss(s);
        string temp,ans="";
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans+=temp+' ';
        }
            ans.pop_back();
            return ans;
    }
};
```