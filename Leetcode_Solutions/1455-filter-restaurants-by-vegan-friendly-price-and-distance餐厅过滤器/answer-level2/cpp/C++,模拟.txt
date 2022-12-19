```
inline bool cmp(vector<int>&a,vector<int>&b){
    if(a[1]!=b[1])return a[1]>b[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>ans;
        //ans.clear();
        //int n=restaurants.size();
        for(auto r:restaurants){
            int id=r[0],rating=r[1],vegan=r[2],price=r[3],dist=r[4];
            if(veganFriendly==1&&vegan==0)continue;
            if(price>maxPrice)continue;
            if(dist>maxDistance)continue;
            ans.push_back(r);
        }
        sort(ans.begin(),ans.end(),cmp);//对符合条件的进行排序，然后输出。
        vector<int>res;
        for(auto x:ans){
            res.push_back(x[0]);
        }
        return res;
    }
};
```
