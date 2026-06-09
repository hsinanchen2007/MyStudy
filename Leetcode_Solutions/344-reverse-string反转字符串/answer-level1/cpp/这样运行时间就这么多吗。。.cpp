### 解题思路

此处撰写解题思路
### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i = 0; i < len/2; i++)
        {
            char temp;
            temp = s[i];
            s[i] = s[len-i-1]; 
            s[len-i-1] =temp;
        }
    }
};
```