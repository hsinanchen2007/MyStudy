过滤，利用sort排
```
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> leftRes;
        for (int i = 0; i < restaurants.size(); i++) {
            if (veganFriendly == true && restaurants[i][2] == 0) {
                continue;
            }
            if (restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance) {
                continue;
            }
            leftRes.push_back({-1*restaurants[i][1], -1*restaurants[i][0]});
        }
        sort(leftRes.begin(), leftRes.end());
        vector<int> ans;
        for (int i = 0 ; i < leftRes.size(); ++i) {
            ans.push_back(-1*leftRes[i][1]);
        }
        return ans;
    }
};
```
