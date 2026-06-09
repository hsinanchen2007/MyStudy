### 解题思路
双100

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int zeroNum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroNum++;
            }
        }
        int gapSum = 0;
        
        if(zeroNum >= 1) {
            for(int j= zeroNum+1;j<nums.size();j++) {
                if( nums[j] - nums[j-1] == 0) {
                    return false;                    
                }
                    gapSum += nums[j] - nums[j-1];
               
            }
            if( (5 - zeroNum-1) + zeroNum  >=  gapSum ) {
                return true;
            }else{
                return false;
            }

        }else{
                for(int j= 1;j<nums.size();j++) { 
                if( nums[j] - nums[j-1] == 0  && nums[j] != 0 && nums[j-1] != 0) {
                    return false;                    
                }               
                    gapSum += nums[j] - nums[j-1];                
                }
                if(gapSum == 4){
                    return true;
                }else{
                    return false;
                }
        }
        return true; 
    }
};
```