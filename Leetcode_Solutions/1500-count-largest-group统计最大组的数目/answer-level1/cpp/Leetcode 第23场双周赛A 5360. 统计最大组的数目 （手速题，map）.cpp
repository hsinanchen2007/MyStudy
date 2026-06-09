```
class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>p;
        int maxx=-1;
        for(int i=1;i<=n;i++)
        {
            int tep=i,sum=0;
            while(tep)
            {
                sum+=tep%10;
                tep/=10;
            }
            p[sum]++;
            maxx=max(maxx,p[sum]);
            
        }
        int cnt=0;
        for(auto it:p)
        {
            if(it.second==maxx)cnt++;
        }
        return cnt;
    }
};
```
