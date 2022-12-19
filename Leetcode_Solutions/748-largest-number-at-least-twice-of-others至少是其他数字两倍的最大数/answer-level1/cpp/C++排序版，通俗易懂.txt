class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1)
        return 0;
        vector<int> m(nums.begin(),nums.end());//拷贝数组
        sort(nums.begin(),nums.end());//排序
        if(nums[nums.size()-1]<2*nums[nums.size()-2]) return -1;//判断最大值是否小于第二大值的二倍
        for(int i=0;i<nums.size();i++)
        {
            if(m[i]==nums[nums.size()-1]) return i;//寻找原来数组最大值的索引，然后返回
        }
        return -1;//这一步看似多余，但是不写编译不能通过

    }
};