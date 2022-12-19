### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 0;
        digits.back() += 1;
        for(int i = digits.size() - 1 ; i >= 0 ; i--)
        {
            digits[i] += carry;
            if(digits[i] > 9)
            {
                digits[i] %= 10;
                carry = 1;
            }
            else
                carry = 0;
            if(carry == 0)
                break;
        }
        if(carry == 1)
        ans.push_back(1);
        for(int i = 0 ; i < digits.size() ; ++i)
            ans.push_back(digits[i]);
        return ans;
    }
};
```