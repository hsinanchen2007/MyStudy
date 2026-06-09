### 解题思路
这道题目比上一道题目还简单一些，就是先排序，然后利用 a + b + c = target -> a + b = target - c，转换为在有序数组找两数之和
然后使用两个指针去进行寻找答案。

但是这道题目我把问题想复杂了，因为上一道题目，需要使用去重进行剪枝，这道题，我怀疑也要剪枝。
因此使用了
(1) if(target < nums[0] + nums[1] + nums[2]) return nums[0] + nums[1] + nums[2];
        if(target > nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3]){
            return nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3];
        }
    }
(2) 使用 larger_flag 与 smaller_flag 剪枝，但是这一步错了。当遭遇
[1,2,4,8,16,32,64,128]
82 = 2 + 16 + 64
当i = 1, nums[i] = 2的时候，2+4+128 > 82 -> larger_flag = true；下一次while循环 2+4+64 < 82 ->smaller_flag。
这样会miss掉2 + 16 + 64, 因此导致错误。

此外，这也提示我们以后可以尝试使用2^n作为test case去测试我们的code

### fail代码
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return -1;
        int res = nums[0] + nums[1] + nums[2], len = nums.size();
        if(target < nums[0] + nums[1] + nums[2]) return res;
        if(target > nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3]){
            return nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3];
        }
        for(int i = 0; i < len-2; ++i){
            int t = target - nums[i];
            int l = i+1, r = nums.size()-1;
            bool larger_flag = false, smaller_flag = false;//error
            while(l < r){
                if(larger_flag && smaller_flag){//error
                    break;//error
                }//error
                if(nums[l] + nums[r] == t){
                    return target;
                }else if(nums[l] + nums[r] > t){
                    larger_flag = true;//error
                    if(abs(res - target) > abs(nums[l] + nums[r] + nums[i] - target)){
                        res = nums[l] + nums[r] + nums[i];
                    }
                    --r;
                }else{
                    smaller_flag = true;//error
                    if(abs(res - target) > abs(nums[l] + nums[r] + nums[i] - target)){
                        res = nums[l] + nums[r] + nums[i];
                    }
                    ++l;
                }
            }
        }
        return res;
    }
};
```


### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return -1;
        int res = nums[0] + nums[1] + nums[2], len = nums.size();
        if(target < nums[0] + nums[1] + nums[2]) return res;
        if(target > nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3]){
            return nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3];
        }
        for(int i = 0; i < len-2; ++i){
            int t = target - nums[i];
            int l = i+1, r = nums.size()-1;
            while(l < r){
                //cout << "res: " << res << endl; 
                if(nums[l] + nums[r] == t){
                    return target;
                }else if(nums[l] + nums[r] > t){
                    if(abs(res - target) > abs(nums[l] + nums[r] + nums[i] - target)){
                        res = nums[l] + nums[r] + nums[i];
                    }
                    --r;
                }else{
                    if(abs(res - target) > abs(nums[l] + nums[r] + nums[i] - target)){
                        res = nums[l] + nums[r] + nums[i];
                    }
                    ++l;
                }
            }
        }
        return res;
    }
};
```

### 结果
执行用时 : 16 ms , 在所有 C++ 提交中击败了 32.18% 的用户 
内存消耗 : 6.6 MB , 在所有 C++ 提交中击败了 100.00% 的用户