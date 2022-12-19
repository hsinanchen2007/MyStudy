### 解题思路
第一种算set的长度 长度不对则有重复的数
第二种参考别人的方法 swap一下 但是不知道为啥我提交的运行时间并不快

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // int n = nums.size();
        // int len1 = 0;
        // int len2 = 0;
        // set<int> set1;
        // for(int i = 0; i < n; ++i){
        //     set1.insert(nums[i]);
        //     len2 = set1.size();
        //     if(len2 == len1){return nums[i];}
        //     len1 = len2;
        // }
        // return 0;
        // 用时144ms
        int n = nums.size();
        
        for(int i = 0; i < n; ++i){
            while(i != nums[i]){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
```