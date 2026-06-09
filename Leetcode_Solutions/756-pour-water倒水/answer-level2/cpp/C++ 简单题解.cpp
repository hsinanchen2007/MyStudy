```C++ []
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int N = heights.size();
        for (int i = 0; i < V; ++i) {
            int j = K;
            while (j - 1 >= 0 && heights[j] >= heights[j - 1]) --j;
            while (j < K && heights[j] == heights[j + 1]) ++j;
            if (j != K) {
                ++heights[j];
                continue;
            }
            j = K;
            while (j + 1 < N && heights[j + 1] <= heights[j]) ++j;
            while (j > K && heights[j] == heights[j - 1]) --j;
            ++heights[j];
        }
        return heights;
    }
};
```
或者
```C++ []
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int N = heights.size();
        for (int i = 0; i < V; ++i) {
            int j = K;
            int ind = K;
            while (j - 1 >= 0 && heights[j - 1] <= heights[j]) {
                if (heights[j - 1] < heights[j]) {
                    ind = j - 1;
                }
                --j;
            }
            if (ind != K) {
                ++heights[ind];
                continue;
            }
            j = K;
            ind = K;
            while (j + 1 < N && heights[j + 1] <= heights[j]) {
                if (heights[j + 1] < heights[j]) {
                    ind = j + 1;
                }
                ++j;
            }
            ++heights[ind];
        }
        return heights;
    }
};
```


![image.png](https://pic.leetcode-cn.com/97367643f37331d33af06aa7b368cbd4aaa9e33f01c0471df9399043b91cde23-image.png)
