### 解题思路
一看到连续正数序列，不用想，**一定是前缀和+MAP或者前缀和+二分查找**

如下代码用的是前缀和+map

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        int length = (target + 1) / 2;
        vector<int> presum = vector<int>(length + 1, 0);
        unordered_map<int, int> sumindexmap;
        vector<vector<int>> result;

        presum[0] = 0;

        for (int i = 1; i < presum.size(); i++) {
            presum[i] = presum[i - 1] + i;
            sumindexmap[presum[i]] = i;
        }

        for (int i = 0; i < presum.size(); i++) {
            int part = target + presum[i];
            vector<int> buff;
            int j = 0;
            if (sumindexmap.count(part)) {
                j = sumindexmap[part];
            }

            for (int k = i + 1; k <= j; k++) {
                buff.push_back(k);
            }

            if (!buff.empty()) {
                result.push_back(buff);
            }
        }

        return result;
    }
};
```