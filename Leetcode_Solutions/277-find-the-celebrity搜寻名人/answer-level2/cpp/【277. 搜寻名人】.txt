## 思路一：暴力遍历
判断是否存在一列值都为1，然后判断以改列值为行号的行是否除本身为都为0，如果是，返回列值，否则返回-1。
### 代码
```c++
class Solution {
public:
    int findCelebrity(int n) {
        for (int j = 0; j < n; ++j) {
            int i;
            for (i = 0; i < n; ++i) {
                if (!knows(i, j)) {
                    break;
                }
            }
            if (i == n) {
                int k;
                for (k = 0; k < n; ++k) {
                    if (k != j && knows(j, k)) {
                        break;
                    }
                }
                if (k == n) {
                    return j;
                }
            }
        }
        return -1;
    }
};
```

## 思路二：贪心
先假设0为名人候选人，遍历其它人i，如果候选人认识i，则修改候选人为i。最后验证候选人是否是名人。
### 代码
```c++
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;        
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) {
                res = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != res && (knows(res, i) || !knows(i, res))) {
                return -1;
            }
        }
        return res;
    }
};
```


