思路：先排序，然后用二分找到每个房子最近的加热器，求出最大值. 二分的时候可以使用上一次的结果进行剪枝，不过好像影响不大。

```
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        long index = 0;
        long size = heaters.size();
        for (int i=0; i<houses.size(); i++) {
            int h = houses[i];
            int r = 0;
            if (index == size) {
                r = h - heaters[size-1];
            } else {
                index = lower_bound(heaters.begin()+index, heaters.end(), h) - heaters.begin();
                if (index == size) {
                    r = h - heaters[size-1];
                } else if (index == 0) {
                    r = heaters[0] - h;
                } else {
                    r = min(heaters[index] - h, h - heaters[index-1]);
                }
            }
            res = max(r, res);
        }
        return res;
    }
};
```