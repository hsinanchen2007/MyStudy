### 解题思路
第一次下意识用暴力法提交超时了，然后看了下 [wu_yan_zu](https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/) 的解题思路，豁然开朗，这里用c++实现了一下，仅供参考

执行用时 :88 ms, 在所有 C++ 提交中击败了47.68% 的用户
内存消耗 : 13.9 MB, 在所有 C++ 提交中击败了 100.00% 的用户

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nSize = nums.size();
        vector<vector<int>> result;
        if (nSize < 3) {
            return result;
        }

        sort(nums.begin(),nums.end());
        int L,R;
        for (int i = 0; i < nSize; i++) {
            if (nums[i] > 0) return result;
            if (i > 0 && nums[i] == nums[i - 1]) continue; //对于重复元素，跳过，避免出现重复解
            L = i + 1;
            R = nSize - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    vector<int> tmp = {nums[i], nums[L], nums[R]};
                    result.push_back(tmp);
                    //去重
                    while (L < R && nums[L] == nums[L+1]) {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R-1]) {
                        R--;
                    }
                    L++;
                    R--;
                } else if (sum < 0) { //说明nums[L]太小的，L++
                    L++;
                } else if(sum > 0) { //说明nums[R]太大了，R--
                    R--;
                }
            }
        }
        return result;
    }
};
```