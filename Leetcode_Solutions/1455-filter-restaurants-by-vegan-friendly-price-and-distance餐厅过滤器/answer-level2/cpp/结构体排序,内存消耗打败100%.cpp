### 解题思路
此处撰写解题思路

### 代码

```cpp

struct node{
    int id;
    int pa;
} a[10000];
bool cmp (node aa,node bb){
    if (aa.pa==bb.pa){
        return aa.id>bb.id;
    }
    return aa.pa>bb.pa;
}
class Solution {
public:


    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int cnt = 0;
        int sum = 0;
        for (auto v:restaurants){
            if (v[2]==0&&veganFriendly==1) continue;
            if (v[3]<=maxPrice&&v[4]<=maxDistance){
                a[cnt].id= v[0];
                a[cnt++].pa= v[1];
            }
        }
        sort(a,a+cnt,cmp);
        vector<int> ret;
        for (int i = 0;i<cnt;i++){
            ret.push_back(a[i].id);
        }
        return ret;
    }
};
```