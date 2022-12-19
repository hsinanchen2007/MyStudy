### 解题思路
先将num取绝对值，然后通过取模7，结果插在最前面。再根据原值是否为负数，加负号

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        if(num == 0) return "0";
        int val = num;
        num = abs(num);
        while(num){
            res.insert(0, to_string(num%7));
            num /= 7;
        }
        if(val < 0) res.insert(0, "-");
        return res;
    }
};
```