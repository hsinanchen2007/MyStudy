>1.状态：
>>1.选择当前元素start，对start+2开始的剩余部分继续求解
>>2.不选择当前元素strart，对start+1开始的剩余部分继续求解

>2.结束条件：
>>剩余一个元素，则返回该元素

通过表避免重复计算
```
class Solution {
public: 
    int Massage(vector<int>& nums,int start,vector<int>& table){
        if(start>nums.size()-1)return 0;
        if(start==nums.size()-1) return nums[start];
        if(table[start]!=-1)return table[start];
        int yes=nums[start]+Massage(nums,start+2,table);
        int no=Massage(nums,start+1,table);
        table[start]=max(yes,no);
        return  max(yes,no);
    }
    int massage(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> table(nums.size());
        fill(table.begin(),table.end(),-1);
        int result = Massage(nums,0,table);
        return result;
    }
};

```