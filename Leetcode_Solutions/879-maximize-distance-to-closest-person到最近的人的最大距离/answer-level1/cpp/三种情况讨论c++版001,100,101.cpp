```
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N = seats.size();
        int pr = -1, fu = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (seats[i] == 1) {
                pr = i;
            } else {
                fu=i+1;
                ans = max(ans, (fu-pr)/2);
                if(fu==N)
                ans=max(ans,fu-pr-1);
                if(pr==-1)
                ans=max(ans,fu-pr-1);
            }
        }
        return ans;
    }
};
```
