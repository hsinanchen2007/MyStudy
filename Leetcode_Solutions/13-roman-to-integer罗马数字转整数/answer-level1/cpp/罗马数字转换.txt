### 解题思路
这题不用判断输入罗马数字是否合法，简单很多

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int total = 0, pre = 0, flag = 1;
        for(string::size_type i = s.size(); i > 0; i--){
            int tem = 0;
            switch(s[i - 1]){
                case 'I' : tem = 1; break;
                case 'V' : tem = 5; break;
                case 'X' : tem = 10; break;
                case 'L' : tem = 50; break;
                case 'C' : tem = 100; break;
                case 'D' : tem = 500; break;
                case 'M' : tem = 1000; break;
            }
            if(tem < pre)flag = -1;
            total = total + flag * tem;
            pre = tem;
            flag = 1;
        }
        return total;
    }
};
```