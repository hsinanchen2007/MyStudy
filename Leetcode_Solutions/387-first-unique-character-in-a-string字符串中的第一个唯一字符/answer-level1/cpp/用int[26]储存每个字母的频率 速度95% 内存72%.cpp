### 解题思路
两次遍历即可 时间复杂度O(N)

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s)
    {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (auto c : s)
            arr[c - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (arr[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
```