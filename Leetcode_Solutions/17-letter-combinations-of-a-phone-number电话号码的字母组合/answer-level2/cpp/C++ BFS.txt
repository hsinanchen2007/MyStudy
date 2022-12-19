### 解题思路
逐层往下扩展

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> keybord;
        keybord['2']="abc";
        keybord['3']="def";
        keybord['4']="ghi";
        keybord['5']="jkl";
        keybord['6']="mno";
        keybord['7']="pqrs";
        keybord['8']="tuv";
        keybord['9']="wxyz";
        vector<string> temp;
        int n=digits.length();
        if (n==0) return temp;
        return cat(0,n,digits,keybord,temp);
    }
    vector<string> cat(int i,int n,string dig,unordered_map<char,string> key,vector<string> temp){
            string cur_str=key[dig[i]];
            vector<string> next_str;
            if (temp.size()==0) {
                for (int k=0;k<cur_str.length();k++){
                    next_str.push_back(cur_str.substr(k,1));
                }
            }
            else {
                for (int j=0;j<temp.size();j++){
                    for (int k=0;k<cur_str.length();k++){
                        next_str.push_back(temp[j]+cur_str[k]);
                    }
                 }
            }
            if (i<n-1) return cat(i+1,n,dig,key,next_str);
            return next_str;
    }
};
```