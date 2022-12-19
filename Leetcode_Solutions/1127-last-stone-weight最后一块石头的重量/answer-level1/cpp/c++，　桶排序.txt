### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) {
            return 0;
        }
        vector<int> dict(1001, 0);
        int count = 0;
        for (auto val : stones) {
            dict[val] += 1;
            count += 1;
        }
        int index = dict.size() - 1;
        int f, s;
        while (count > 1) {
            while (count > 1 && dict[index] == 0) {
                index -= 1;
            }
            if (dict[index] >= 2) {
                count -= 2;
                dict[index] -= 2;
            } else {
                f = index - 1;
                while (f >= 0 && dict[f] == 0) {
                    f -= 1;
                }
                if (f < 0) {
                    return dict[index];
                } else {
                    count -= 2;
                    if (dict[f] == 1) {
                        dict[f] = 0;
                    } else {
                        dict[f] -= 1;
                    }
                    dict[index] = 0;
                    int val = index - f;
                    if (val > f) {
                        index = val;
                    } else {
                        index = f;
                    }
                    dict[val] += 1;
                    count += 1;
                }
            }
        }
        if (count < 1) {
            return 0;
        }
        while (index >= 0 && dict[index] == 0) {
            index -= 1;
        }
        return index;
    }
};
```