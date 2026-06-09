### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int length = s.size();
        char reversrString[length + 1];

        for(int i = 0; i < length; i++){
            if(i < (length - n)){
            reversrString[i] = s[i + n];
            }
            if(i >= (length - n)){
            reversrString[i] = s[i - (length - n)];
            }
        }
        reversrString[length] = '\0';
        string ss = reversrString;
        return ss;
    }
};
```

需要将char数组长度加一，同时在末尾加上‘\0‘，再转变为string