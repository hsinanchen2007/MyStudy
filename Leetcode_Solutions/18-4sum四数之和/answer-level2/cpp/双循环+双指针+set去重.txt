```
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        
        sort(nums.begin(), nums.end());
        
        set<vector<int> > result;
        int i, j = 1, p = j + 1, q, sum = 0;
        
        //  双循环，相当于固定两个数
        for (j = 1; j < nums.size() - 2; ++j)
            for (p = j + 1; p < nums.size() - 1; ++p) {
                i = 0;
                q = nums.size() - 1;
                //  双指针移动，左右缩小范围
                while (i < j && q > p) {
                    sum = nums[i] + nums[j] + nums[p] + nums[q];
                    //  判断是否需要插入,用set去除重复元素
                    if (sum == target) {
                        result.insert( {nums[i], nums[j], nums[p], nums[q]} );
                        if (nums[i] == nums[q]) break;
                        i++;
                    } else if (sum < target) i++;
                    else if (sum > target) q--;
                }
            }
        return vector<vector<int> >(result.begin(), result.end());
    }
```