### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string res = S;
        int tmp = 0;
        int len = shifts.size();
        for (int i = len - 1; i >= 0; i--)
        {
            tmp += shifts[i] % 26;
            res[i] = ((res[i] + tmp - 97) % 26) + 'a';
        }
        
        return res;
    }
};

```