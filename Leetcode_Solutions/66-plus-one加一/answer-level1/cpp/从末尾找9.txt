### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while(i >= 0)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
                break;
            i--;
        }

        if(i < 0)
        {
            digits.insert(digits.begin(), 1);
        }
        else
        {
            digits[i]++;
        }
        return digits;
    }
};
```