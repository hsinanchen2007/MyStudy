```
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = houses.size(), n = heaters.size(), j = 0, res = 0;
        for(int i=0; i<m; i++) {
            int cur = houses[i];
            // 当前的房子离下一个加热器更近时，选择下一个加热器
            while(j < n-1 && abs(heaters[j+1] - cur) <= abs(heaters[j] - cur)) {
                j++;
            }
            // while循环后，此时选出的灭火器的位置是离当前房子最近的灭火器，此时更新res
            res = max(res, abs(heaters[j] - cur));
        }
        return res;
    }
};
```
