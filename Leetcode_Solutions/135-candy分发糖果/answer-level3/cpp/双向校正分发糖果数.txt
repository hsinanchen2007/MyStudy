贪心法，双向遍历，校正分发糖果数，然后求和。
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> cd(ratings.size(),1);
        for(int i=1; i<cd.size(); ++i)
            if(ratings[i]>ratings[i-1]) cd[i] = cd[i-1]+1;
        for(int i=cd.size()-1; i; --i)
            if(ratings[i-1]>ratings[i] && cd[i-1]<=cd[i]) cd[i-1]=cd[i]+1;
        return accumulate(cd.begin(),cd.end(),0);
    }
};
```
