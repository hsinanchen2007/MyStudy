### 解题思路
![搜狗截图20年04月04日2019_1.png](https://pic.leetcode-cn.com/6197e1d1c08d71335e89baf59bc44e504cdbce4f82e96b67c660659f2d282701-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20%E5%B9%B404%E6%9C%8804%E6%97%A52019_1.png)

总体思想：
1. 遍历vector中的每一个值height[i]；
2. 以该值height[i]为区间的左侧起点，继续向后遍历，查找是否存在一个可以作为盛水区间右侧的点height[j]，判断标准为height[j]需要是height[i]右侧的一个峰值且大于或等于height[i]；
3. 将所有的区间以pair的形式汇总到一个vector（std::vector<std::pair<int, int> > pairs）中；
4. 针对pairs中的每个区间，求区间内的盛水量，即可得到总的盛水量。

### 代码

```cpp
class Solution {
public:
    static int calc(vector<int>& height, int left, int right)
    {
        int res = 0;

        int high = height[left] < height[right] ? height[left] : height[right];

        for (int i = left; i < right + 1; ++i) {
            res += (high - height[i] > 0) ? (high - height[i]) : 0;
        }

        return res;
    }

    int trap(vector<int>& height) {
        std::vector<std::pair<int, int> > pairs;
        int count = height.size();

        int i = 0;
        for (; i < count; ) {
            if (height[i] == 0) {
                ++i;
                continue;
            }

            int j = i + 1;
            std::pair<int, int> highest = std::make_pair(0, 0);
            for (; j < count; ++j) {
                if (height[j] > highest.second) {
                    highest.first = j;
                    highest.second = height[j];
                    if (height[j] >= height[i]) {
                        break;
                    }
                }
            }

            if (highest.second > 0) {
                pairs.push_back(std::make_pair(i, highest.first));
                i = highest.first;
                continue;
            }

            ++i;
        }

        int total = 0;

        for (auto eachPair : pairs) {
            total += calc(height, eachPair.first, eachPair.second);
        }

        return total;
    }
};
```