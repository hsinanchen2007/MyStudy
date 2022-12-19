```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flg=0;//逆序发生次数
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){//逆序发生
                if(flg==1)return 0;//第二次逆序直接gg
                else{
                    flg=1;
                    if(i==1||nums[i-2]<=nums[i]);//可以减小前一个的话就减小前一个，不影响后面的判断所以省略
                    else nums[i]=nums[i-1];//无法减小前一个，只能把后一个增加
                }
            }
        }
        return 1;
    }
};
```
