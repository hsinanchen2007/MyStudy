- 将字符串address 逐个复制到一个新的空字符串上，当遇到'.'时，在新的数组上写入"[.]" ，否则只需将字符复制上去即可。
```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char i : address){
            if(i != '.')    ans.push_back(i);
            else    ans += "[.]";
        }
        return ans;
    }
};
```
