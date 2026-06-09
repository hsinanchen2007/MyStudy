### 解题思路
二分模板

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 0) return -1;
        while (n > 0 && nums[n] == nums[0]) n -- ;  //[4,5,6,7,0,1,2,3,4,4,4]
        if (nums[n] >= nums[0]) return nums[0]; //[4,5,6,7,4,4,4]后排数组完全单调的情况，被删完了...
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;       // [l, mid], [mid + 1, r]
            if (nums[mid] <= nums[n]) r = mid; //[4,5,6,7,3]所以要取等号
            else l = mid + 1;
        }
        return nums[r];
    }
};
```