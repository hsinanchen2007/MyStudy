### 解题思路
sum * 2 + nums[i] == sumALL

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         if (nums.size() == 2) {
            return -1;
        }
        int sum = 0;
        int sumALL = 0;
        for (int& it : nums) {
            sumALL += it;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (sum * 2 + nums[i] == sumALL) {
                return i ;
            }
            sum += nums[i];
        }
        return -1;

    }
};
```