```
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int res=INT_MAX;
        int max=24*60;
        for(int i=0;i+1<timePoints.size();++i){
            auto tmp=toSecond(timePoints[i+1])-toSecond(timePoints[i]);
            res=min({res,tmp,max-tmp});
        }
        auto tmp=toSecond(timePoints[timePoints.size()-1])-toSecond(timePoints[0]);
        res=min({res,tmp,max-tmp});
        return res;
    }
    int toSecond(string &s){
            return stoi(s)*60+stoi(s.substr(3));
    }
};
```
