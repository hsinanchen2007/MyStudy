### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        // 获取出生中的最小年份
        int min_year = *min_element(birth.begin(), birth.end());
        // 获取死亡中的最大年份
        int max_year = *max_element(death.begin(), death.end());
        // 创建一个年份数组，从最小年份~最大年份
        vector<int> human(max_year - min_year + 1, 0);
        for (int i = 0; i < birth.size(); ++i) {
            int start = birth[i], end = death[i];
            while (start <= end) {
                ++human[start - min_year];
                ++start;
            }
        }
        // 寻找人数最多的年份
        int cnt = 0, offset = 0;
        for (int i = 0; i < human.size(); ++i) {
            if (i == 0) {
                cnt = human[i];
                offset = i;
                continue;
            }
            if (human[i] > cnt) {
                cnt = human[i];
                offset = i;
            }
        }
        return min_year + offset;
    }
};
```