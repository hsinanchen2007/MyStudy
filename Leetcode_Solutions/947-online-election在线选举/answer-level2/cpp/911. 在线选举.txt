### 解题思路
二分查找

### 代码

```cpp
class TopVotedCandidate {
    vector<int> time;
    vector<int> who;
    int n;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        n=persons.size();
        vector<int> vote(n,0);
        who=vector<int>(n);
        time=times;
        int maxperson=0;
        for(int i=0;i<n;++i)
        {
            ++vote[persons[i]];
            if(vote[persons[i]]>=vote[maxperson])
            {
                maxperson=persons[i];
            }
            who[i]=maxperson;
        }
    }
    
    int q(int t) {
        if(t>=time[n-1])return who[n-1];
        if(t<=time[0])return who[0];
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(t>time[mid])
            {
                l=mid+1;
            }
            else if(t<time[mid])
            {
                r=mid;
            }
            else
            {
                return who[mid];
            }
        }
        if(t>=time[l])
            return who[l];
        else
            return who[l-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```