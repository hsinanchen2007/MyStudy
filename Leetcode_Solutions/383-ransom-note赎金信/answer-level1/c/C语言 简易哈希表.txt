### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (auto m : magazine)
            arr[m - 'a']++;
        for (auto r : ransomNote)
            arr[r - 'a']--;
        for (int i = 0; i < 26; i++)
            if (arr[i] < 0)
                return 0;
        return 1;
    }
};
```