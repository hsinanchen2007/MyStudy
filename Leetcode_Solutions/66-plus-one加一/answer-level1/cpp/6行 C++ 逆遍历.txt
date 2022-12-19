```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1, carry=1; i>-1; digits[i--] %= 10){
            digits[i] = digits[i] + carry;
            carry = digits[i] > 9;
        }
        if(!digits[0]) digits.insert(digits.begin(), 1);
        return digits;
    }
};
```
- 从向量末尾开始逐个` + carry`，并计算是否进位
- 如果`for`循环之后`vector`首位为`0`，则代表最后一次计算需要进位