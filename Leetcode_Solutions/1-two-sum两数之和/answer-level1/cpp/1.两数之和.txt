### 解题思路
因为示例直接给的vector所以用了它，思路就是不断向下比较（耗时太久了TT）。第一次刷leetcode还有点懵，不太习惯，输入输出样例只有一组

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j ;
        vector<int> result(2) ;
        for(i=0; i<nums.size(); i++){
            for(j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    result[0] = i ;
                    result[1] = j ;
                }
            }
        }
        return result ;
    }
};
```