### 解题思路
思路很简单,删除K个数可以分解成每次删除一个数让这个数最小.然后删除k次;
列: num="1432219" k=3
从高位开始选择当前位和之后位最小的数,会让这个数最小.
1:1432219 - 132219 : [1,4]选1,[4,3]选3,删除4.
2:132219  - 12219  : [1,2]选2,[3,2]选2,删除4.
3:12219   - 1219   : [1,2]选2,[2,2]选2,[2,1]选1,删除2

### 代码 

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        if(len <= k) return "0";
        for(int i = 0; i < k; ++i) {
            int j = 0;
            while(num[j] <= num[j+1] && j < len-1) j++;
            num.erase(j,1);
        }
        while(num[0]=='0'&&num.length() != 1)num.erase(0,1);
        return num;
    }
};
```