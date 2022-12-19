```
class Solution {
public:
    vector<vector<int> > rects;
    vector<int> areas;
    int total = 0;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        areas.push_back(0);
        for (auto& rec : rects) {
            int a = (rec[2] - rec[0] + 1) * (rec[3] - rec[1] + 1);
            areas.push_back(areas.back() + a);
        }
        total = areas.back();
    }
    
    vector<int> pick() {
        int r = rand() % total + 1;
        int index = lower_bound(areas.begin(), areas.end(), r) - areas.begin() - 1;
        int delta = r - areas[index] - 1;
        int width = rects[index][2] - rects[index][0] + 1;
        int x = delta % width + rects[index][0];
        int y = delta / width + rects[index][1];
        return {x, y};
    }
};
```

![image.png](https://pic.leetcode-cn.com/bfef378c5d73984f755998b7c9914ada37c83c395345afa806541533e16172e4-image.png)
