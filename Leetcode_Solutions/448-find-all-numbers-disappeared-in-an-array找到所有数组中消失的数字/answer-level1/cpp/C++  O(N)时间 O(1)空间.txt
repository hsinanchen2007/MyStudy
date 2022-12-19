### 解题思路
遍历原数组，将每个数值i存放到i-1处，遍历新的数组，找到nums[i]!=i+1的即为消失的元素。

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[nums[i]-1] != nums[i]){
                int tmp = nums[i];
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
            } else {
                i++;
            }
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
```