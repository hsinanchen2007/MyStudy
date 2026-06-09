### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> resarray;
        int fp=0,sp=fp+1,tp,length,tans,cnt=0,fl;
        sort(nums.begin(),nums.end());
        length=nums.size();
        if(length<3||nums[0]>0||nums[length-1]<0)return resarray;
        while(fp<length-2&&nums[fp]<=0)  //jianzhi
        {
            tp=length-1;   //every cycle must
            sp=fp+1;
            tans=0-(nums[fp]+nums[sp]);
            while(tp>sp)  //jianzhi
            {
                for(;tp>sp&&tans<nums[tp];tp--);  //tp>sp,or overflow
                    vector<int> res;
                    if(nums[tp]==tans&&tp>sp)  //tp right sp left
                    {
                        res.push_back(nums[fp]);
                        res.push_back(nums[sp]);
                        res.push_back(nums[tp]);
                        resarray.push_back(res);
                    }
                fl=nums[sp];
                for(;sp<tp&&nums[sp]==fl;sp++);
                if(sp<tp)
                    tans=0-(nums[fp]+nums[sp]);
            }
            fl=nums[fp];
            for(;fp<length-2&&nums[fp]<=0&&nums[fp]==fl;fp++);
        }
        return resarray;

    }
};
```