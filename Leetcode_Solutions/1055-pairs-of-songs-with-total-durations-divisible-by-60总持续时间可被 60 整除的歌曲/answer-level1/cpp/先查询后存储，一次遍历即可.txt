```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int i,c=0,s=time.size();
        vector<int> a(61,0);
        for(i=0;i<s;i++)
        {
            c+=a[(60-time[i]%60)%60];
            a[(time[i]%60)]++;
        }
        return c;
    }
};
```
