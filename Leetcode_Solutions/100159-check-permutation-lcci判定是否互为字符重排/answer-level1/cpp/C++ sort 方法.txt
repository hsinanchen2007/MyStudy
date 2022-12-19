### 解题思路
sort就完事了


### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
      	sort(s1.begin(), s1.end());
	    sort(s2.begin(), s2.end());
	    return s1 == s2;  
    }
};
```