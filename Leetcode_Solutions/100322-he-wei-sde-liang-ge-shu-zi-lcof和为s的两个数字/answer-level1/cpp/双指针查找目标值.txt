### 解题思路
设置左右指针一起查找和为target的两个数，算法复杂度为O(n);
但仅击败了10.10%；
可以考虑加上二分查找来减少查找但数，使得算法复杂度为O(logn)。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        vector<int> re;
        while(left<right){
            if ((nums[left]+nums[right]) == target){
                re.push_back(nums[left]);
                re.push_back(nums[right]);
                break;
            }
            else if ((nums[left]+nums[right]) > target){
                right--;
                continue;
            }
            else if ((nums[left]+nums[right]) < target){
                left++;
                continue;
            }
        }
        return re;
    }
};
```