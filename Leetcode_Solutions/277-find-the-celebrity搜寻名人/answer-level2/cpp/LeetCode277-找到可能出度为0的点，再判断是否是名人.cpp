### 解题思路

1. 设待定名人candidate为0， 遍历每一个人，candidate认识另一个人i，说明他不是名人，把i变成名人。
2. 最后再判断是不是所有人都认识他，而他不认识所有人

为什么第一步能找到可能的名人（出度可能为0）证明：
反证法： 假如找到candidate的不是名人，说明出度不为0。 
但若该candidate出度不为0，则轮到candidate的时候一定会转移，矛盾。

那有没有可能漏掉名人呢？答案是否定的，因为名人一定不认识其他人，并且其他人都是认识他，迭代了n次之后，最后会收敛到一定是名人。

### 代码

```cpp
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        // 找到出度为0的点
        for (int i = 0; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        
        // 看看是不是所有人都认识他 和 是否他不认识所有人
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (!knows(i, candidate)) return -1;
                if (knows(candidate, i)) return -1;
            }
        }
        return candidate;
    }
};
```