### 解题思路
记录两个字符串中字符出现的次数。
然后，以t为基准，将t中多的消去就可以了

### 代码

```cpp
class Solution {
public:
    //hash计数
    int minSteps(string s, string t) {
        int a[26] = {0};
        int b[26] = {0};
        for(int i=0;i<s.size();i++){
            a[s[i] - 'a']++;
            b[t[i] - 'a']++;
        }
        int res = 0;
        //这里应该是26才对
        for(int i=0;i<26;i++){
            //这个代表t中有多的数
            if(a[i] < b[i]) res = res + b[i] - a[i];
        }
        return res;
    }
};
```