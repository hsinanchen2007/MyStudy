### 解题思路
去重+两个指针
重点说下去重：一旦与上一次循环的元素一样，直接跳过。
因为上一次循环的元素，总的元素更多，搜索空间更大，搜索出来的结果一定包含本次循环搜索的结果

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < len-3; ++i){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            for(int j = i+1; j < len-2; ++j){
                int l = j + 1, r = len - 1;
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                while(l < r){
                    if(nums[i] + nums[j] + nums[l] + nums[r] == target){
                        if(l == j+1 || r == len-1){
                            vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                            res.push_back(tmp);
                            --r; ++l;
                        }else if(nums[l] == nums[l-1] || nums[r] == nums[r+1]){
                            --r; ++l;
                            continue;
                        }else{
                            vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                            res.push_back(tmp);
                            --r; ++l;
                        }
                    }else if(nums[i] + nums[j] + nums[l] + nums[r] > target){
                        --r;
                    }else{
                        ++l;
                    }
                }
            }
        }
        return res;
    }
};

```

### 结果
执行用时 : 240 ms , 在所有 C++ 提交中击败了 5.95% 的用户 
内存消耗 : 7.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户