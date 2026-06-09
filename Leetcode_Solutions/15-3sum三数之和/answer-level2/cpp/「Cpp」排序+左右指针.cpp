### 解题思路

这题目最讨厌的地方是不能有重复元素，因此在代码中有三处是用于判断重复

第一层循环的指针，每次移动的时候是不是和前面的元素一样

```cpp
if (i > 0 && nums[i] == nums[i-1]) continue; // 重复元素1
```

第二层循环的时候，如果当前结果满足要求

- left的左移一位，如果等于当前值，那么跳过
- right右移一位，如果等于当前值，那么跳过

```cpp
while (left <right && nums[left] == nums[left+1]) left++;  // 重复元素2
while( left <right && nums[right] == nums[right-1]) right--;  // 重复元素3
```

另外还有两个特例专用语句

- 数组不能太小 `if (nums.size() < 3) return ret; //元素不够`
- 当前元素不能大于0，如果大于0，后面肯定也大于0 `if (nums[i] > 0) break;`

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ret; //结果
        sort(nums.begin(), nums.end()); //排序
        if (nums.size() < 3) return ret; //元素不够

        vector<int> curr(3,0); //临时保存中间结果
        
        int left, right;
        for (int i = 0; i < nums.size() - 2; i++){

            if (nums[i] > 0) break;
            
            if (i > 0 && nums[i] == nums[i-1]) continue; // 重复元素1
            // 左右指针
            left = i+1;
            right = nums.size()-1;
            int target = -nums[i];
            while(left < right){
                if (nums[left] + nums[right] > target){
                    right--;
                } else if(nums[left] + nums[right] < target){
                    left++;
                } else{
                    curr[0] = nums[i], curr[1] = nums[left], curr[2] = nums[right];
                    ret.push_back(curr);
                    
                    //去重
                    while (left <right && nums[left] == nums[left+1]) left++;  // 重复元素2
                    while( left <right && nums[right] == nums[right-1]) right--;  // 重复元素3
                    left++;
                    right--;
                }
                
            }
        }
        return ret;
        
    }
};
```