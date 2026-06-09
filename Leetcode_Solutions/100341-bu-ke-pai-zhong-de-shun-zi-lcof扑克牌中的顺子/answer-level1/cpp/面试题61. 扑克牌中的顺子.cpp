```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if (nums.size() < 5)
            return false;
        sort(nums.begin(), nums.end());
        int numZero = 0;
        int numBlank = 0;
        for (int i = 0; i < 5; i++){
            if (nums[i] == 0)  // 统计0的次数
                numZero++;
            else {   //统计空掉的数字数
                if (i + 1 < 5) {
                    if (nums[i+1] == nums[i])
                        return false;
                    else
                        numBlank += nums[i+1] - nums[i] - 1;
                }
            }
        }
        if (numZero >= numBlank)
            return true;
        return false;

    }

};
```