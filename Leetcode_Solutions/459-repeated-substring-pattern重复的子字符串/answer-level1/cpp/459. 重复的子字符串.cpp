### 解题思路
转
设 s=abab; s+s=abababab,从下标1开始寻找s，若s为子串重复多次构成，则find返回的值不会为下标4，即第二个s的开头
设 s=abc; s+s=abcabc,从下标1开始寻找s,返回值为3,即第二个s的开头,因为s=abc不是子串重复多次构成的

### 代码

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s,1)!=s.size();
    }
};
```