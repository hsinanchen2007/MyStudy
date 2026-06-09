### 解题思路
利用二维数组hash[2001][2]充当哈希表，第一维存储各个正数的个数，第二维存储各个负数个数，存储时直接利用当前数（正数情况）或其相反数（负数情况）作为下标进行存储，如111存储在hash[111][0]处，-111存储在hash[111][1]处，然后使用该表判断是否存在满足题意的数。

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      bool result = false;
      int hash[2001][2] = {0};
      for (auto it : arr) {
        if (it >= 0) {
          hash[it][0] += 1;
        } else {
          hash[-it][1] += 1;
        }
      }
      for (auto it : arr) {
        if (it == 0) {
          if (hash[0][0] > 1) {
            result = true;
          }
        } else if (it > 0) {
          if (hash[2 * it][0] > 0) {
            result = true;
          }
        } else {
          if (hash[2 * (-it)][1] > 0) {
            result = true;
          }
        }
      }
      return result;
    }
};
```