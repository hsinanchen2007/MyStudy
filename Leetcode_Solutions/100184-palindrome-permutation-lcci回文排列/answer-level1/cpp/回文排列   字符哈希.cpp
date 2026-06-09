### 解题思路
判定字符串是否为某个回文串的排列（本身可以不是）
字符hash计算个数，偶数ok，激素只能有一项。
### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int used[256]={0};
        for(int i=0;i<s.length();i++){
            used[s[i]]++;
        }
        int flag=0;
        for(int i=0;i<256;i++){
            if(used[i]%2!=0){
                flag++;
            }
        }
        return flag<2;
    }
};
```