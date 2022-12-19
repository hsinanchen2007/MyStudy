### 解题思路
ipv4地址格式为x.x.x.x。所以本题中直接提取值存放在临时字符串（数组）中，当address[i] == '.'时，暴力添加"[.]"并continue。
因为添加了临时字符串的缘故，相比直接在原数组上处理方便了很多。下面两种分别是用字符串/字符型数组的解答。

### 代码

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
            for(size_t i = 0; i < address.length(); i++){
                if(address[i] == '.'){
                    ans += "[.]";
                    continue;
                }
                ans += address[i];
            }
        return ans;
    }
};
```
```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        int length = address.length();
        vector<string>pause(length);
        int j = 0;
            for(size_t i = 0; i < length; i++){
                if(address[i] == '.'){
                    j++;
                    continue;
                }
                pause[j] += address[i];
            }
        string ans = pause[0]+"[.]"+pause[1]+"[.]"+pause[2]+"[.]"+pause[3];
        return ans;
    }
};
```