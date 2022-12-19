### 解题思路
参考了其他大佬的快慢双指针：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/solution/ti-jie-shou-wei-shuang-zhi-zhen-kuai-man-shuang-zh/

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int fast = 0;
        int low = 0;
        int size = nums.size();
        for(;fast < size; fast++){
            if(nums[fast]&1 == 1){
                swap(nums[low],nums[fast]);
                low++;
            }
        }
        return nums;
    }
};
```