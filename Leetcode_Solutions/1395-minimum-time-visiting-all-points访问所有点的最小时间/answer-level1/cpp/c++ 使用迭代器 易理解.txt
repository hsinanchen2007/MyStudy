### 解题思路




### 代码

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        vector<vector<int> >::iterator i;
        for(i = points.begin(); i != points.end()-1; i++){
            vector<int> a = *i, b = *(i+1);
            ans += max(abs(b[1]-a[1]), abs(b[0]-a[0]));
        }
        return ans;
    }
};
```