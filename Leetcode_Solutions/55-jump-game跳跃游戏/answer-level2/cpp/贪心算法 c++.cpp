![image.png](https://pic.leetcode-cn.com/e3f1b45ef29ac8df1f0996dd21083aff9184418be104bc877d1f0f1850407031-image.png)

思路：每一次在上一次的最大值和这次的最大值之间填true值 最后看看能不能到达最后一个
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()<=1) return true;
        bool result[nums.size()] = {false};
        int i=0;
        int lastmax = 0;
        while(i<nums.size()){
            int ini = i;
            int maxnum = ini+nums[ini];
            for(i = lastmax;i<=ini+nums[ini] and i<nums.size();i++){
                if(i+nums[i]>maxnum){
                    maxnum = i+nums[i];
                }
                result[i] = true;
            }
            i--;
            for(;i<=maxnum and i<nums.size();i++){
                result[i] = true;
            }
            i--;
            lastmax = ini+nums[ini];
            if(ini == i){
                break;
            }
        }
        return result[nums.size()-1];
        
    }
};
```
