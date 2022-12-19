```
class Solution {
public:
    int getKth(int lo, int hi, int k) {
     map<int,int> mp;
     while(lo<=hi)
     {
         int k=lo;
         int count=0;
         while(k!=1)
         {
             if(k%2==0) k=k/2;
             else k=3*k+1;
             count++;
         }
         mp[lo]=count;
         lo++;
     }
    vector<pair<int,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),[=](const pair<int,int>& p1,const pair<int,int>& p2){
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second<p2.second;
    });
        for(auto i:v)
        {
            --k;
            if(k==0) return i.first;
        }
        return 0;
    }
};
```
