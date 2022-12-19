```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len < 1){
            return false;
        }
        if(len == 1){
            return true;
        }
        int tmp = -1;
        for(int i=0; i<len;i++){
            if(nums[i] == 0){//碰到0的时候看之前的向右延伸的最远距离能不能超过当前这个0的位置，超不过就不能到达以后的位置
                if(tmp <= i){
                    if(i != len-1){
                        return false;
                    }else{
                        return true;
                    }
                }
            }
            tmp = max(tmp, nums[i]+i);
        }
        return true;
    }
};
```
