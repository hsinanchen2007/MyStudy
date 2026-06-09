```
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int res=0;
        int p0=0;
        int p1=people.size()-1;
        while(p0<p1)
        {
            if(people[p0]+people[p1]<=limit)++p0;
            --p1;
            ++res;
        }

        if(p0==p1)++res;

        return res;
    }
};
```
