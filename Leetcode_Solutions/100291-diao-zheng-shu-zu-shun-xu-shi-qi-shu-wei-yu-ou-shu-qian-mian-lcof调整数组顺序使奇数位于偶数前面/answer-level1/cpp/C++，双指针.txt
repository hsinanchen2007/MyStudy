### 解题思路
C++，双指针

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            while(nums[l]%2==1&&l<r){
                l++;
            }
            while(nums[r]%2==0&&l<r){
                r--;
            }
            swap(nums[l],nums[r]);
            l++,r--;
        }
        return nums;
    }
};
```