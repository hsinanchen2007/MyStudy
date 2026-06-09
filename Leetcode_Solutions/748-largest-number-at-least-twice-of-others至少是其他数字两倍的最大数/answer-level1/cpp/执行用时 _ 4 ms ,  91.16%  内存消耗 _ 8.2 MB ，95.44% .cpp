```
/*
        关键：不使用排序的情况下存储最大的两个元素
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        pair<int,int> max_tmp;          //存储最大值和下标
        max_tmp.first = 0;
        int sec_tmp = 0;                //存储第二大元素
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>=max_tmp.first){
                sec_tmp = max_tmp.first;
                max_tmp.first = nums[i];
                max_tmp.second = i;
            }else if(nums[i]>=sec_tmp){
                sec_tmp = nums[i];
            }
        }
        if(sec_tmp == 0){               //分母为零，且分子不为零，无穷大
            if(max_tmp.first > 0)
                return max_tmp.second;
        }else{
            if(max_tmp.first/sec_tmp >1)//一般情况下至少大于两倍的判别
                return max_tmp.second;
        }

        return -1;
    }
};
```
