## 思路
先对数组进行排序，然后从头开始遍历，通过固定第一个数，将三数之和转为两数之和。因为要避免重复，所以在遍历过程中，如果遇到相同数，则进行跳过。
### 代码
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        if (size < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());        
        for (int i = 0; i < size; ++i) {
            int target = - nums[i];
            int L = i+1, R = size - 1;
            while (L < R) {
                int sum = nums[L] + nums[R];
                if (sum == target) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[L]);
                    tmp.push_back(nums[R]);
                    res.push_back(tmp);
                    ++L;
                    --R;
                    //处理第二个重复数字
                    while (L < R && nums[L] == tmp[1]) {
                        ++L;
                    }
                    //处理第三个重复数字
                    while (L < R && nums[R] == tmp[2]) {
                        --R;
                    }
                } else if (sum > target) {
                    --R;
                } else {
                    ++L;
                }
            }    
            //处理第一个重复数字
            while (i+1 < size && nums[i] == nums[i+1]) {
                ++i;
            }
        }
        return res;
    }
};
```
