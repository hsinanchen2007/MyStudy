### 解题思路
用双指针进行判断，当两边都是字母的时候就交换位置，否则，指向不是字母的指针移动，是字母的指针则保持不动，等待交换位置。

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int begin = 0;
        int end = S.size()-1;
        while(begin <= end)
        {
            if(!isalpha(S[begin]))
                begin++;
            else if(!isalpha(S[end]))
                end--;
            else if(isalpha(S[begin]) && isalpha(S[end]))
            {
                swap(S[begin], S[end]);
                begin++;
                end--;
            }
        }  
        return S;      
    }
};
```