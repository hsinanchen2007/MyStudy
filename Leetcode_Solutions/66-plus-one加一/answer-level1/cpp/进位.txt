### 解题思路
注意判断一下最后的进位就好了

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      if(digits.size() == 0)  return {};
      int flag = 0;
      for(int i = digits.size() - 1; i >= 0; i--){
        int sum = digits[i] + flag;
        sum = i == digits.size() - 1 ? sum + 1 : sum;

        digits[i] = sum % 10;
        flag = sum / 10;
        if(flag == 0) break;
      }

      if(flag == 1){
        digits.insert(digits.begin(), 1);
      }

      return digits;
    }
};
```