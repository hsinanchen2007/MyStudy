
直接用位运算，已知两个相同的数异或之后为0，所以把数组所有的数都异或了之后就是剩下的值了

```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum^=nums[i];
        }
        return sum;
    }
};
```
