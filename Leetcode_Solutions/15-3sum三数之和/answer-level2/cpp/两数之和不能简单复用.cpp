这道题我是觉得很赞的，很多点做起来很有意思。

整体思路——三数之和为零，那么就代表 nums[j] + nums[k] = nums[i] * -1。然后把i从数组中移除，就变成了两数之和。

但是，这个题又跟两数之和不同。两数之和是找index，这个则是找value。
所以，两数之和没法用排序后，两个指针一头一尾来找，所以用了一个hash来解决。
三数之和却可以这么干，但三元组用hash的话，大概率超时。如果是出题人专门这样出的话，我真的要点个赞。

这道题还有两个难点。
**第一，不能有重复的三元组**
这个如果复用二元组的hash的话。不排序的话，就需要额外定义一个map来判断是不是重复。
但数据结构的插入和寻找，hash虽然都号称o(1)，但肯定也不如直接两个指针找起来快。
并且排序后，可以快速的剔除出重复元组。

**第二，[0,0,0] [0,0,0,0,0]的特征case**
这个的解决方案也很巧

整体而言，从两数之和做到三数之和，这个思考的过程我还是很享受的。

```
 vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {            
            if (i != 0 and nums[i] == nums[i - 1]) {
                continue;
            }
            int begin = i + 1;
            int end = nums.size() - 1;
            int target = -1 * nums[i];
            while (begin < end) {
                if (nums[begin] + nums[end]  == target) {
                    result.push_back({nums[i], nums[begin], nums[end]});
                    ++begin;
                    --end;
                    //这个操作不能放在外面一层，是为了防止[0,0,0]这样的的情况出现
                    while (begin < end and nums[begin] == nums[begin - 1]) {
                    //while是为了防止[0,0,0,0,0]的情况出现
                        ++begin;
                    }
                    while (begin < end and nums[end] == nums[end + 1]) {
                        --end;
                    }
                }
                else if (nums[begin] + nums[end] < target) {
                    ++begin;
                }
                else {
                    --end;
                }
            }  
        }
        return result;
    }
```
