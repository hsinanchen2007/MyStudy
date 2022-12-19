```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subre;
        unsigned int mask = 0;
        sort(nums.begin(), nums.end());
        backtrack(nums, result, subre, mask, 0);  
        return result; 
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& subre, unsigned int& mask, int idx){
            // cout<<idx<<": "<<mask<<" vs. "<<((1<<nums.size())-1)<<endl;
            if(mask == ((1<<nums.size()) - 1))
            {
                cout<<"push "<<endl;//<<subre[0]<<" "subre[1]<<" "<<subre[2]<<endl;
                result.push_back(subre);
                return ;
            }
            int pre;
            bool flg = true;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(mask & (1<<i)) continue;
                // 剪枝，nums已经排序，若此轮与上一轮选择的数字相同，则略过，保持答案唯一性。
                if(flg)
                {
                    pre = nums[i];
                    flg = false;
                }
                else if(nums[i] == pre)
                {
                    continue;
                }
                else
                {
                    pre = nums[i];
                }
                // cout<<"round-"<<idx<<", check "<<nums[i]<<endl;
                mask |= (1<<i);
                subre.push_back(nums[i]);
                backtrack(nums, result, subre, mask, idx+1);   
                mask &= ~(1<<i);
                subre.pop_back();
            }

                
    }
};
```
