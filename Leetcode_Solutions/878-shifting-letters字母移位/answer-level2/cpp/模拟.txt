### 解题思路


### 代码

```cpp
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for(int i = shifts.size() - 2 ; i >= 0 ; i--)
            shifts[i] += shifts[i + 1] % 26;
        for(int i = 0 ; i < shifts.size() ; ++i)
        {
            int change = S[i] - 'a';
            change += shifts[i];
            change %= 26;
            S[i] = change + 'a';
        }
        return S;
    }
};
```