如果做过前几题的话应该大致思路能写出来，本题的关键在于如何处理重复数组，

如数据：{-1,-5,-5,-3,2,5,0,4},{-1,0,1,2,-1,-4}

主要是开始循环时的处理，这里要避免重复选入，有三点，

一是第一次循环不能过滤

二是满足一后，作为固定值的两个元素都要避免与上一次相同

三是不能越界

满足这三点之后代码就很容易地写出来了，效率还可以，48ms以及9.1mb

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        int c,d,sum;
        vector<vector<int>>res;
        for(int pos_d=0;pos_d<nums.size();pos_d++){
            if(pos_d>0&&nums[pos_d]==nums[pos_d-1]) continue;
            d = nums[pos_d];
            for(int pos_c=pos_d+1;pos_c<nums.size();pos_c++){
                if(pos_c>pos_d+1&&pos_c-1>0&&nums[pos_c]==nums[pos_c-1]) continue;
                c = nums[pos_c];
                sum = target -(d + c);
                int i = pos_c+1,j=nums.size()-1;
                while(i<j){
                    if(nums[i]+nums[j]==sum){
                        res.push_back(vector<int>{d,c,nums[i],nums[j]});
                        while(i+1<j&&nums[i+1]==nums[i]) i++;
                        while(j-1>i&&nums[j-1]==nums[j]) j--;
                        i++;
                        j--;
                    }else if(nums[i]+nums[j]>sum){
                        j--;
                    }else if(nums[i]+nums[j]<sum){
                        i++;
                    }
                }
            }
        }
        /*打印
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        return res;
    }

};
```

