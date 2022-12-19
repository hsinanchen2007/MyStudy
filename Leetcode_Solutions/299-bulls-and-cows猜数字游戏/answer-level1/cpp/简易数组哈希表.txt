### 解题思路
两次遍历，先记录位置正确的，再记录位置不正确的

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int len = secret.length();
        int arr[10];
        memset(arr, 0 , sizeof(arr));
        for (auto c : secret)
            arr[c - '0']++;
        int A = 0, B = 0;
        for (int i = 0; i < len; i++)
            if (secret[i] == guess[i])
                A++, arr[guess[i] - '0']--;
        for (int i = 0; i < len; i++)
        {
            int g = guess[i] - '0';
            if (secret[i] != guess[i] && arr[g] > 0)
                B++, arr[g]--;
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
```