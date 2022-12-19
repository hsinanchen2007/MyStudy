

```
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2,0);
        int n=nums.size();
        for(int i=0;i<n;++i){
            while(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i])//每次循环都会保证至少i位置或nums[i]-1位置上的元素至少一个归位
                swap(nums[i],nums[nums[i]-1]);   //把nums[i]这个数字放入正确的位置，更新i位置上的数字为nums[nums[i]-1]
            if(nums[i]!=i+1)                 //当i位置上出现的数字不对时(此时nums[i]已经放入正确的位置nums[i]-1)就证明其为重复元素，当缺少元素并不一定为此时的i+1，但肯定为最后的i+1;
                res={nums[i],i+1};
        }
        return res;
    }
};
```
