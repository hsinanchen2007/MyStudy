### 解题思路
此处撰写解题思路
string类自带函数find()，详见C++primer plus page 661
### 代码

```cpp
//string类自带函数find()，详见C++primer plus page 661
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //int pos=-1;
        int pos=haystack.find(needle);
        if(pos>haystack.size())
            return -1;       
         else 
            return pos;
    }
};
```