不断更新当下区间的最右端，当遍历的下标与最右端重合的时候，说明这个区间已经自洽了
```
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty()) return 0;
        int r = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            r = max(r, arr[i]);
            if (i == r) {
                ++res;
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5b75918bc4c9f18a67ddbf47782388394ab45946a2d0c87232eb4fc28a993795-image.png)

