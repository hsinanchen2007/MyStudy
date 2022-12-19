### 解题思路
选取两个人，考察其相识关系。设这两个人分别为`i`和`j`，初始化如下：

```cpp
i = 0, j = 1;
```

如果`knows(i, j)`为真，则`i`不可能是名人，而`j`是一个候选名人，我们作如下修改：

```cpp
i = j;
++j;
```

否则，我们只是`++j`。一个值得注意的地方是我们始终保持`i < j`。当`j >= n`时我们结束考察，因为题目给定了恰好有一个名人或者没有，所以`i`是唯一的候选名人或者不是，但我们还不能确定，需要作进一步判断，一个平凡的方法就是考察`i`和其他人的关系，如果`i`认识其中任一人或有人不认识`i`，则说明没有名人。最后，如果以上都不成立，则`i`为名人。

### 代码

```cpp
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0, j = 1;
        while (j < n) {
            if (knows(i, j)) {
                // i cannot be a celebrity, j may be a celebrity
                i = j;
                ++j;
                
            } else {
                ++j;
            }
        }
        // i is a candidate
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            if (knows(i, k) || !knows(k, i)) return -1;
        }
        return i;
    }
};
```