### 解题思路
i是左指针，j是右指针，每次找到下一个字母并设置边界判断是否需要交换。

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.length()-1;
        while (i < j){
            while (i < j && (!isalpha(S[i]))) i++;
            while (i < j && (!isalpha(S[j]))) j--;
            if (i < j) swap(S[i],S[j]);
            i++; j--;
        }
        return S;
    }
};
```