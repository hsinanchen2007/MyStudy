第三次独立结题，撒花

特殊情况就一种，目标值比最后一个元素大，单独考虑，其他情况利用for遍历即可

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(target>nums.back()){
            return len;
        }
        for(int i = 0; i<len; i++){
            if(target<=nums[i]){
                return i;
            }
        }
         return -1;
    }
};
```
