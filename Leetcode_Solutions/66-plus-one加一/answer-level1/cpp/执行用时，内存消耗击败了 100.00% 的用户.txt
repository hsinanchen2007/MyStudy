### 解题思路
这个题目关键要考虑进位的情况，就是[9,9,9]这种情况
其他都很简答，不赘述了

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            int val = digits[i] + carry;
            carry = val / 10;
            val = val % 10;
            digits[i] = val;
        }
        if(carry == 0) return digits;
        vector<int> res(digits.size()+1, 1);
        for(int i = 1; i < res.size(); ++i){
            res[i] = digits[i-1];
        }
        return res;
    }
};
```

###结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户