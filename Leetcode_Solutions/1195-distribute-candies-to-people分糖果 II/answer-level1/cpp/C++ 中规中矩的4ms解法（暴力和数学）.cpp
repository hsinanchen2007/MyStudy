## 暴力版
```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0;
        while (candies) {
            ans[i % num_people] += min(candies, i + 1);
            candies -= min(candies, i + 1);
            ++i;
        }
        return ans;
    }
};
```

## 数学版
```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i < cols) d[i] = (i + 1) * (rows + 1) + (int)(rows * (rows + 1) * 0.5) * n;
            else { if (rows > 0) d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n; }
        }
        d[cols] += remaining;
        return d;
    }
};
```