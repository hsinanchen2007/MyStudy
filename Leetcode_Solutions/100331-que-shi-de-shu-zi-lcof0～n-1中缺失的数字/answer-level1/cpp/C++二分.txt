### 解题思路
这题用二分好坑爹啊。对应[0]、[1]这种输入很蛋疼，二分最后的l会大于size。后面还需要进行判断。

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] != mid) {
                if (mid == 0 || nums[mid-1] == mid - 1) { //mid==0 排除掉[1] 这种输入
                    return mid;
                }
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l >= nums.size() ? nums[l-1] + 1 : nums[l] - 1; //这里需要判断l是不是大于size了
    }
};
```