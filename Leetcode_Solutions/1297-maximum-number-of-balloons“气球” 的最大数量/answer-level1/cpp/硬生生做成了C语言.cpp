### 解题思路
简易哈希表arr代表26个字母的频率

### 代码

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (auto c : text)
            arr[c - 'a']++;
        arr['l' - 'a'] /= 2, arr['o' - 'a'] /= 2;
        char* b = "balon";
        int min = INT_MAX;
        for (int i = 0; i < 5; i++)
            if (arr[b[i] - 'a'] < min) min = arr[b[i] - 'a'];
        return min;
    }
};
```