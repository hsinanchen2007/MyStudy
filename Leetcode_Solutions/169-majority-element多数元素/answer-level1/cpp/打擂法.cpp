### 解题思路
遇到0时，ans换成当前数
遇到不同的数时，nm = nm - 1
遇到相同的数时，nm = nm + 1
最终出现次数过半的数必然胜利
### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], nm = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nm == 0) ans = nums[i];
            if(nums[i] == ans) nm++;
            else nm--;
        }
        return ans;
    }
};
```