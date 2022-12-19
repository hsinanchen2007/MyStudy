这个方法是参考评论区各位大佬的；
需要注意的一些情况：
1、输入为空；
2、输入个数小于3个
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result_set;
        if(nums.size() < 3)
        {
            return result_set;
        }
        std::sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int end = nums.size() - 1;
            int mid = i + 1;
            if(nums[i] > 0 ) {
                break;
            }
            else if (i -1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            else {
                while (end > mid) {
                    int s_0 = nums[i] + nums[mid] + nums[end];
                    if(s_0 < 0){
                        mid++;
                    }
                    else if(s_0 > 0){
                        end--;
                    }
                    else{
                        result_set.push_back({nums[i],nums[mid],nums[end]});
                        while (mid < end && nums[mid] == nums[mid + 1]){
                            mid++;
                        }
                        while (mid < end && nums[end] == nums[end - 1]){
                            end--;
                        }
                        mid++;
                        end--;
                    }
                }
            }
        }
        return result_set;
    }
};
```