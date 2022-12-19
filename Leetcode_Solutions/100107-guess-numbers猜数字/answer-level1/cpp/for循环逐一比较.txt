### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int times=0;
        for (int i=0;i!=3;++i)
        {
            if(guess[i]==answer[i])
            ++times;
        }
    return times;
    }
};
```