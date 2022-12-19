### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        map<char,int>table = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
        vector<int>vt;
        for(int i = 0;i<s.size();i++){
            if(table.count(s[i]) != 0){
                vt.push_back(i);
            }

        }
        char temp;
        for(int l = 0,r = vt.size()-1;l<r;l++,r--){
            temp = s[vt[l]];
            s[vt[l]] = s[vt[r]];
            s[vt[r]] = temp;
        }

        return s;
    }
};
```