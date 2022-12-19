### 解题思路
利用map，遍历string。首先建立一个Map来映射符号和值，然后对字符串从左到右来，如果当前字符代表的值不小于其右边，就加上该值；否则就减去该值。
注意：1、unordered_map效率比hash_map、map高，空间复杂度hash_map最低，map最高。
     2、使用map.insert()可以直接插入列表{ {}，{}，{} }使插值更简洁。

### 代码

```cpp
#include<map>
#include<iostream>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> rome;
        rome.insert({{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}});
        int len = s.size();
        int sum = 0 ;
        for(int i = 0 ; i < len ; i++ ){
            sum =  rome[s[i]] < rome[s[i+1]] ?  sum - rome[s[i]] : sum + rome[s[i]];
        }
        return sum;
    }
};
```