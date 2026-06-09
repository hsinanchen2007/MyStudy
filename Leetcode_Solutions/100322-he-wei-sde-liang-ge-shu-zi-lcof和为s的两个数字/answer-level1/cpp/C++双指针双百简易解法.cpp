### 解题思路
从第一个和最后一个元素开始算。
如果算出来的结果比目标大，那就最后一个往前移，否则就第一个目标往后移。

88ms, 21.5MB
![image.png](https://pic.leetcode-cn.com/9b2da029198721c97a2d5655d159baf211502b8ef1d0016e6d5fca900e823326-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  // 双指针
        vector<int> result;
        int sum, i = 0, j = nums.size()-1;
        while(i < j){
            sum = nums[i]+nums[j];
            if(sum==target){
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                break;
            }
            if(sum>target) j--;
            else i++;
        }
        
        return result;
    }
};
```