### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i=0; i<s.size()/2; i++)
        {
            char former = s[i];                               //前后对称调换
            s[i] = s[len-1-i];
            s[len-1-i] = former;

        }
        
    }
};
```