```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max=0,now=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                max=1;
                now=1;
            }else{
                if(nums[i]>nums[i-1]) now++; //now记录每一次
                else {
                    max=max>now?max:now;   //递增结束比较一下
                    now=1;                 //记得更新now的值
                }
            }
        }
        return max>now?max:now;  //如果一直递增到结束，没机会赋值给max；每次都这里出错
    }
};
```
