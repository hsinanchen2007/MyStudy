### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto last_one = digits.back();
  int ori_size = digits.size();
  auto plus_one = last_one;
  // std::cout << plus_one << std::endl;
  int i = ori_size - 1;
  while (i >= 1) {
    plus_one++;
    if (plus_one == 10) {
      digits[i] = 0;
    } else {
      digits[i] = plus_one;
      break;
    }
    --i;
    plus_one = digits[i];
  }
  if (i == 0) {
    plus_one++;
    if (plus_one == 10) {
      digits[i] = 0;
      digits.insert(digits.begin(), 1);
    }else {
      digits[i] = plus_one;
    }
    
  }
  return digits;
    }
};
```