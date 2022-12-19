### 解题思路
如果使用暴力做法，那么时间复杂度是O(n^3)。这个显然不是我们想要的。
仔细看题目的要求可以发现a+b+c = 0 -> a+b = -c
经过这样的数学转换后，通过先排序O(nlogn)，然后对有序数组寻找a+b = -c，遍历所有元素O(n)作为c，以及两个指针O(n)寻找a+b
这样的方法时间复杂度是O(n^2)
此外，这道题最关键的是解决去重，如何去重呢？如果使用
如果满足了a+b+c = 0，此时c为target，a+b，一旦a或b与前一个遍历的元素一样。那么一定是重复的。
因为此时a+b = -c，一旦a一样，那么b也一定一样。

我也尝试了使用set去重，但是也仍然超时。


### 使用set超时代码
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res_dup;
        for(int i = 0; i < len; ++i){
            findTarget(i+1, res_dup, nums, -1 * nums[i]);
        }
        set<vector<int>> s;
        for(auto i: res_dup){
            s.insert(i);
        }
        for(auto i: s){
            res.push_back(i);
        }
        return res;
    }

    void findTarget(int l, vector<vector<int>> &s, vector<int>& nums, int target){
        int r = nums.size() - 1;
        vector<int> sum_zero;
        sum_zero.push_back(-1*target);
        while(l < r){
            if(nums[l] + nums[r] == target){
                sum_zero.push_back(nums[l]);
                sum_zero.push_back(nums[r]);
                s.push_back(sum_zero);
                sum_zero.pop_back();
                sum_zero.pop_back();
                ++l; --r;
            }else if(nums[l] + nums[r] > target){
                --r;
            }else{
                ++l;
            }
        }
    }
};
```

### Pass代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            if(i == 0 || nums[i] != nums[i-1]){
                findTarget(i+1, res, nums, -1 * nums[i]);
            }
        }
        return res;
    }

    void findTarget(int l, vector<vector<int>> &s, vector<int>& nums, int target){
        int r = nums.size() - 1, start = l, end = nums.size() - 1;
        vector<int> sum_zero;
        //sum_zero.push_back(-1*target);
        while(l < r){
            if(nums[l] + nums[r] == target){
                if(l == start || r == end){
                    vector<int> sum_zero({-target, nums[l], nums[r]});
                    s.push_back(sum_zero);
                    ++l; --r;
                }else if(nums[l] == nums[l-1] || nums[r] == nums[r+1]){
                    ++l; --r;
                }else{
                    vector<int> sum_zero({-target, nums[l], nums[r]});
                    s.push_back(sum_zero);
                    ++l; --r;
                }
                
            }else if(nums[l] + nums[r] > target){
                --r;
            }else{
                ++l;
            }
        }
    }
};
```

### 结果
执行用时：164 ms
内存消耗：13.7 MB