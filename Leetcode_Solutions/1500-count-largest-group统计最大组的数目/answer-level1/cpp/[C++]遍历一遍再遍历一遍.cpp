第一遍先转存到map里边，然后第二遍从map中统计最大。

```C++ []
class Solution {
  public:
    int countLargestGroup(int n) {
        std::unordered_map<int, int> umap;

        int sum = 0, tmp = 0;
        for (int i = 1; i <= n; ++i) {
            tmp = i;
            sum = 0;
            while (tmp != 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            umap[sum]++;
        }

        int max_num = 0, max = 0;
        for (auto &m : umap) {
            if (max < m.second) {
                max = m.second;
                max_num = 1;
            } else if (max == m.second)
                max_num++;
        }
        return max_num;
    }
};
```