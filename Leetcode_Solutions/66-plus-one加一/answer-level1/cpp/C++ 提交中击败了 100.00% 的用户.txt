### 解题思路
直接从最后一位开始加,然后进位.

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        vector<int> res;
        int iCarry = 0;
        for (int i = n-1; i>=0 ; --i)
        {
            int incre = (i == n-1) ? 1 : 0;
            auto num = digits[i] + incre;
            num += iCarry;
            iCarry = num/10;
            num = num % 10;
            res.insert(res.begin(), num);
        }
        if (iCarry)
            res.insert(res.begin(), iCarry);
        
        return res;
    }
};
```