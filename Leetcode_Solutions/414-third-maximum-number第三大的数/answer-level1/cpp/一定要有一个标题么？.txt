```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long temp[3]={LONG_MIN,LONG_MIN,LONG_MIN};
        for(auto item:nums){
//更新最大值
            if(item>temp[0]){
                temp[2]=temp[1];
                temp[1]=temp[0];
                temp[0]=item;
//更新第二大
            }else if(item<temp[0] && item>temp[1]){
                temp[2]=temp[1];
                temp[1]=item;
//更新第三大
            }else if(item<temp[1] && item>temp[2]){
                temp[2]=item;
            }
        }
        return temp[2]==LONG_MIN?temp[0]:temp[2];
    }
};
```
