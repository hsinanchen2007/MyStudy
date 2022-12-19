
执行结果：通过  显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了91.42%的用户
内存消耗 :9.3 MB, 在所有 cpp 提交中击败了84.69%的用户
res记录到当前位置最大连续序列的长度，temp记录当前记录的字串的长度，后值大于前值，就将当前长度temp++，
后值小于等于前值，就将当前长度置为1.从当前值重新开始记录
记录的值temp与res进行比较，选择最大长度
```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int res=1;
        int temp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                temp++;
            else if(nums[i]<=nums[i-1])
                temp=1;
            res=max(res,temp);
        }
        return res;
    }
};
```
