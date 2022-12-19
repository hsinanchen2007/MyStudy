```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;

        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            rightSum += nums[i];
        }

        for (int index = 0; index < nums.size(); index++) {
            int tmp = nums[index];
            rightSum -= tmp;

            if (leftSum == rightSum)
                return index;
                
            leftSum += tmp;
        }

        return -1;
    }
};
```
