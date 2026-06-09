### 解题思路
1.排序
2.判断长度
3.比较对应位置是否相等
### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int len = s1.size() - 1;
        int len1 = s2.size()- 1;

        if (len != len1)
        {
            return false;
        }
        
        for (int i = 0; i <= len; i++)
        {
            if (s1[i] != s2[i])
            {
                return false;
            }
        }

        return true;
    }
};
```