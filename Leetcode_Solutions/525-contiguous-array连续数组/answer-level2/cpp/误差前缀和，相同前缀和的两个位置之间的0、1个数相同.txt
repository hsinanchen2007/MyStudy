O(n)的时间复杂度
err是前缀序列误差（0比1多为负，1比0多为正）
因为数组下标不能为负，取个偏移即可
flag存储偏移量第一次出现对应的下标left_id，当有相同偏移量出现时，该下标right_id和first_id之间的序列为01个数相同的序列，之差即为满足条件的长度，迭代取最大即可。

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    int maxn=0;
    int flag[100050];
    memset(flag,-1,sizeof(flag));
    int err=0;
    const int shift=50005;
    flag[shift]=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
            err--;
        else
            err++;
        if(flag[err+shift] == -1)
            flag[err+shift]=i+1;
        else
            maxn=max(maxn,i-flag[err+shift]+1);
    }
    return maxn;
    }
};