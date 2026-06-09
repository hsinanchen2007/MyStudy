### 解题思路
![QQ截图20200328101910.png](https://pic.leetcode-cn.com/c0e24b039e359bb596e6b3e6b7725f2cc0e042305b97c1b219a543e026806ff0-QQ%E6%88%AA%E5%9B%BE20200328101910.png)

### 代码

```cpp
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        // min: 10xxx -> 01(sort(xxx, -1));
        // max: 01xxx -> 10(sort(xxx));

        // INT_MAX 没有最大值, 1没有最小值
        if (num <= 0 || num == INT_MAX) return {-1, -1};
        int minv = INT_MAX, maxv = INT_MIN;
        
        // 计算minv:
        if (num == 1) minv = -1;
        else {
            minv = num;
            int cnt = 0;
            for (int i = 0; i <= 30; i ++) {
                if (!(num >> i & 1) && (num >> (i + 1) & 1)) {
                    // 10xxx;
                    minv -= 1 << (i + 1);
                    minv += 1 << i;
                    while (cnt --) minv += 1 << (--i);
                    break;
                } else if ((num >> i & 1)) {
                    cnt ++;
                    minv -= 1 << i; // 并且就减去该位的1
                }
            }
        }

        // 计算maxv
        if (num == INT_MAX) maxv = -1;
        else {
            maxv = num;
            int cnt = 0;
            for (int i = 0; i <= 30; i ++) {
                if ((num >> i & 1) && !(num >> (i + 1) & 1)) {
                    // 01xxx -> 10xxx
                    maxv += 1 << (i + 1);
                    maxv -= 1 << i;
                    i = 0;
                    while (cnt --) maxv += 1 << (i ++);
                    break;
                } else if ((num >> i & 1)) {
                    cnt ++;
                    maxv -= 1 << i; // 并且就减去该位的1
                }
            }        
        }

        return {maxv, minv};
    }
};
```