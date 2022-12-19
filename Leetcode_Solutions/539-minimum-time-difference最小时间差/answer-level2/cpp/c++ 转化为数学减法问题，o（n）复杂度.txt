```
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> m;
        int res=INT_MAX;
        int offset=1440;
        for(auto i:timePoints){
            int minites=(i[0]-'0')*10+i[1]-'0';
            int second=(i[3]-'0')*10+i[4]-'0';
            m.push_back(minites*60+second);
        }
        int size=m.size();
        for(int i=0;i<size;i++){
            m.push_back(m[i]+offset);
        }
        sort(m.begin(),m.end());
        for(int i=1;i<m.size();i++){
            res=min(res,m[i]-m[i-1]);
        }
        return res;
    }
};
```
