class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>ans(ratings.size());
        ans[0]=1;
        for(int i=0;i<ratings.size()-1;++i)
        {
            if(ratings[i]<ratings[i+1])
            {
                ans[i+1]=ans[i]+1;
            }
            else
            {
                ans[i+1]=1;
            }
        }
        for(int i=ratings.size()-1;i>0;--i)
        {
            if(ratings[i]<ratings[i-1]&&ans[i-1]<ans[i]+1)  //要求满足左规则的前提下，去再满足右规则
            {
                ans[i-1]=ans[i]+1;
            }
        }
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
    }
};