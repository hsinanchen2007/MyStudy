```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int i,j;
        for(i=1;i!=1<<nums.size();++i){
            for(j=31;j>=0;j--){
                if(i&(1<<j)){
                    break;
                }
            }
            //remove highest bit
            auto temp=res[i^(1<<j)];
            temp.push_back(nums[j]);
            res.push_back(temp);
        }
        return res;
    }
};
```
去除最高位之后，之前的子集一定已经计算过（即temp），可以直接加以使用。