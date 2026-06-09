### 解题思路
转成字符串进行处理

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int x=1,y=0;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            x*=s[i]-'0';
            y+=s[i]-'0';
        }
        return x-y;
    }
};
```