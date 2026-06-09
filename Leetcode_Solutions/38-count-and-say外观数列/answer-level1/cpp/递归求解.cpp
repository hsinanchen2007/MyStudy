### 解题思路
找到递归的逻辑链和初始值，应该就没问题了。

### 代码

```cpp
class Solution {
public:
    //递归求解
    string countAndSay(int n) {
        if(n == 1) return "1";
        string last_s = countAndSay(n-1);
        string res;
        int count = 1;
        for(int i=0;i<last_s.size();i++){
            if(last_s[i] == last_s[i+1]) count++;
            else{
                res = res + to_string(count) + last_s[i];
                count = 1;
            }
        }
        return res;
    }
};
```