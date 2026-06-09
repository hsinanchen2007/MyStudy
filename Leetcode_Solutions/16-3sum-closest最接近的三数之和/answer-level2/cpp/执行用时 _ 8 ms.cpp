### 解题思路
与 3 num 类似

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int sum_num;
        int colest_num = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < len; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = len-1;
            while(j < k){
                sum_num = nums[i] + nums[j] + nums[k];
                if(abs(sum_num - target) < abs(colest_num - target)) colest_num = sum_num;
                if(sum_num < target){
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }else if(sum_num > target){
                    k--;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }else return target;
            }
        }
        return colest_num;
    }
};
```