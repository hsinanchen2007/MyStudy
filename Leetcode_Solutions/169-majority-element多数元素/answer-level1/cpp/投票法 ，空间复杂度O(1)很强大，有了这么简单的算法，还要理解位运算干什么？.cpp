### 解题思路

思路清洗且简单，很好理解。从首个元素开始比较统计，如果相同个，则计数加一。如果不相等，则减一，如果这个count的值都小于等于0了，就说明有比当前值更多的元素，这时候更新ans,并重置count计数。这样的空间复杂度是最低的。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0];
        int count = 1;

        for(auto &n : nums) {
            if(ans == n) {
                count++; 
            } else {
                count--;
            }

            if(count <= 0) {
                ans = n;
                count = 1;
            }
        }

        return ans;
    }
};
```