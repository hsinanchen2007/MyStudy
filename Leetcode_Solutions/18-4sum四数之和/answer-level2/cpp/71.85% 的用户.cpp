```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
          vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; i++) {
            if ((nums[i] > target && nums[i] > 0) || (target < 0 && nums[i] > 0))
                break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
           for (int j = i + 1; j < nums.size()-2; j++) {
                 // 不存在
                if(nums[i]+nums[j] > target && nums[i] > 0 && nums[j] > 0 ) break;
                if (target < 0 && nums[i] + nums[j] > 0) break;
            
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int L = j + 1;
                int R = nums.size() -1;    
                while (L < R) {
                    int sum = nums[i] + nums[j] + nums[L] +nums[R];
                    if (sum == target) {
                        result.push_back({nums[i],nums[j],nums[L], nums[R]});
                        while (L < R && nums[L] == nums[L+1]) {
                            L+=1;
                        } //L来到最后一个与nums[L]相等的位置  
                        L+=1;//L+1则来到与nums[L]不等的位置
                        while (L < R && nums[R] == nums[R-1]) {
                            R-=1; 
                        }
                        R-=1;
                    } else if (sum > target) --R;   
                    else ++L; 
                }    
            }          
        }
        return result;                
    }
};
```
