### 解题思路
感觉按着加法逻辑来就行了，从后往前处理进位。
稍有点坑的地方就是进位到最后一位的时候还需要进位

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        for(int i = digits.size()-1;i>-1;--i)
        {
            if(digits[i] == 10)
            {
                digits[i] = 0;
                if(i-1>-1)
                {
                    digits[i-1] += 1;
                }
                else
                {
                    vector<int> res = {1};
                    res.insert(res.end(),digits.begin(),digits.end());
                    return res;
                }
            }
            else
                break;
        }

        return digits;
    }
};
```