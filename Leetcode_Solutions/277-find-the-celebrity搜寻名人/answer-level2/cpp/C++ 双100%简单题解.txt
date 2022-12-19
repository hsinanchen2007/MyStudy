```cpp
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // 先找到名人的候选下标
        int i = 0;
        for (int j = 1; j < n; ++j) {
            if (knows(i, j)) {
                i = j;
            }
        }
        // 判断是否符合条件
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            if (knows(i, j)) return -1;
            if (!knows(j, i)) return -1;
        }
        return i;
    }
};
```


![image.png](https://pic.leetcode-cn.com/39d448e7b3bd94213a10c25a5472e48a30006711e1e5108618c8d9b9263b15c8-image.png)
