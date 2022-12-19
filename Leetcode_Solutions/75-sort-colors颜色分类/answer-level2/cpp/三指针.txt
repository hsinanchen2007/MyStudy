### 解题思路
三指针：0后面，cur，2前面

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int i = 0, cur = 0, j = nums.size()-1, tmp;
        while(cur <= j){
            if(nums[cur] == 0){
                tmp = nums[i];
                nums[i] = nums[cur];
                nums[cur] = tmp;
                i++;
                cur++;
            }
            else if(nums[cur] == 2){
                tmp = nums[j];
                nums[j] = nums[cur];
                nums[cur] = tmp;
                j--;
            }
            else cur++;
        }
    }
};
```