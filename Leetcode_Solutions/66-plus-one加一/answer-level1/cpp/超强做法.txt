### 解题思路
啊我真的好自恋

### 代码

```cpp
class Solution {
    vector<int> rctn(vector<int>& digits, int loc);
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        return rctn(digits,len-1);
    }
};

vector<int> Solution::rctn(vector<int>& digits, int loc)
{
    if (digits[loc] != 9) digits[loc]++;
    else {
        digits[loc] = 0;
        if (loc == 0) {
            vector<int> result;
            result.push_back(1);
            for (auto iter : digits) result.push_back(iter);
            return result;
        }else return rctn(digits, loc - 1);
    }
    return digits;
}
```