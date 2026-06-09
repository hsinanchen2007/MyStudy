- 想象一下，我们要找的数在数组中出现的次数超过一半，那么如果令我们要找的数为1，其它的数为-1，所有的数加起来结果必大于0。
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = nums[0];
        int count = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(target != nums[i]) {
                count--;
                if(count == 0) {
                    target = nums[i];
                    count = 1;
                }
            } else {
                count++;
            }
        }
        
        return target;
    }
};
```
