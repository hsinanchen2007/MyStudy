### 解题思路
1. 初始化一个全为0的存放字母次数的数组a 'z'-'A'=57
2. 记录每个字母出现的次数
3. (a[i]/2)*2使得所有数字都保留偶数个 例如： ccc->cc=2
4. 最后判断如果有多余的加一个放中间，+1

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int res=0;
        int a[58];
        for(int i=0;i<58;i++){
            a[i]=0;
        }
        for(int i=0;i<s.length();i++){
            a[s[i]-'A']++;
        }
        for(int i=0;i<58;i++){
            res+=(a[i]/2)*2;//key step
        }
        if(res<s.length())res++;
        return res;
    }
};
```