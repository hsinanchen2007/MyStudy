1. 遍历数组，元素作为索引对应位置加n
2. 遍历数组，出现两次，则对应位置大于2n
``` C++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index=(nums[i]-1)%n;//对n取余，防止数字越界
            nums[index]+=n;         //对应位置加n
        }
        for(int i=0;i<n;i++)
        {
            //出现两次，则对应位置大于2n
            if(nums[i]>2*n)
                res.push_back(i+1);
        }
        return res;
    }
};
```