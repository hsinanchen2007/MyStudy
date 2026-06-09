这道题别想太复杂了就是将每站上下车的人数统计出来在顺序遍历进行维护数组就成功时间复杂度O(n+n)
`class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int i=0,nums=0;
        vector<pair<int,int>>ans(1000,pair<int,int>(0,0));
        for(i=0;i<trips.size();i++)
        {
            ans[trips[i][1]].first+=trips[i][0];//在同一站要上车的人数
            ans[trips[i][2]].second+=trips[i][0];//在同一站要下车的人数   
        }
        for(i=0;i<1000;i++)
        {
            if(nums>capacity)
                return false;
            nums-=ans[i].second;//遵循先下后上原则
            nums+=ans[i].first;
        }
        return true;
    }
};`