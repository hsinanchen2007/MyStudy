### 解题思路
同三数和问题，用双指针解决
- 先排序(我这里是升序)
- 枚举第一个数nums[i]，k = target - nums[i]
- 接下来用双指针nums[l] 和 nums[r]，让其和更加接近k即可
- 因为枚举的是第一个数，所以nums[l] + nums[r] >= 2 * nums[i]，所以若此时k < 2 * nums[i]可以不用继续了，因为差距只会越来越大
- 用时8ms, 内存6.5MB
### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // ans为最终结果，dis为当前最小差的绝对值
        int ans = 0, dis = -1;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i && nums[i] == nums[i-1]) continue;
            int k = target - nums[i];
            if(dis != -1 && k < (nums[i] * 2)) break;
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] < k) {
                    if(dis == -1) {
                        dis = abs(k - nums[l] - nums[r]);
                        ans = nums[l] + nums[r] + nums[i];
                    }
                    else {
                        if(dis > abs(k - nums[l] - nums[r])) {
                            dis = abs(k - nums[l] - nums[r]);
                            ans = nums[l] + nums[r] + nums[i];
                        }
                    } 
                    while(l < r && nums[l+1] == nums[l]) l++;
                    l++;
                }
                else if(nums[l] + nums[r] > k) {
                    if(dis == -1) {
                        dis = abs(k - nums[l] - nums[r]);
                        ans = nums[l] + nums[r] + nums[i];
                    }
                    else {
                        if(dis > abs(k - nums[l] - nums[r])) {
                            dis = abs(k - nums[l] - nums[r]);
                            ans = nums[l] + nums[r] + nums[i];
                        }
                    }
                    while(l < r && nums[r-1] == nums[r]) r--;
                    r--;
                }
                else return nums[i] + nums[l] + nums[r];
            }
        }
        return ans;
    }
};
```