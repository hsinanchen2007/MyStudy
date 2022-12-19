```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int max = 0;//记录最远可以到达的位置
        for(int i = 0 ; i < nums.size();i++)
        {
         max = max > nums[i]+i ? max :nums[i]+i;
         if (max == i && i!=nums.size()-1) return false; 
         //当最远只能到i处且i不为结尾，就说明没办法跳到结尾。  
        }
       return true;  
    }
};
```
