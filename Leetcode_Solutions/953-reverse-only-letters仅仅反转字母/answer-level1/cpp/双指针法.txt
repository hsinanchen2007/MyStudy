### 解题思路
双指针法，前后找字符，效率空间都是10

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left=0,right=S.size()-1;
        while(left<right)
        {
            while(S[left]<'A'||(S[left]>'Z'&&S[left]<'a')||S[left]>'z')
                ++left;
            while(S[right]<'A'||(S[right]>'Z'&&S[right]<'a')||S[right]>'z')
                --right;
            if(left<right)
            {
                swap(S[left],S[right]);
                ++left;--right;
            }
        }
        return S;
    }
};
```