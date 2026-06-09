### 解题思路
可以采用哈希方式。因为题目是n个数字，取值范围是n-1,因此必有一个是重复的。我们采用换位的方式。即排序，将第i个数放到位置i上。如题解

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i) {
                if(nums[i] == nums[nums[i]])
                {
                   res = nums[i]; 
                   break;
                }
                else{
                    int temp = nums[i];
                    nums[i] = nums[temp];
                    nums[temp] = temp;
                }
            }

            if(res != -1)
                break;
        }
        return res;
    }
};
```