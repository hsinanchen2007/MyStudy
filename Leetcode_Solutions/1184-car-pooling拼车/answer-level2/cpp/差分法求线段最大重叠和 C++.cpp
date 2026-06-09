```
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) { //差分求最大重叠深度
        int len=trips.size();
        vector<int> own(1001, 0);
        int s=1001,e=-1;
        for(int i=0;i<len;i++) {
            int ss=trips[i][1];
            int ee=trips[i][2];
            if (ss<s) {
                s=ss;
            }
            if(ee>e) {
                e=ee;
            }
            own[ss]+=trips[i][0];
            own[ee]-=trips[i][0];
        }
        int ans=0;
        for(int i=s;i<=e;i++) { //累加求得每个车展所载人数
            ans+=own[i];
            if(ans>capacity) {
                return false;
            }
        }
        return true;
    }
};
```
