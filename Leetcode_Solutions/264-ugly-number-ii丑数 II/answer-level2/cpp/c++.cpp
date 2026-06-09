### 解题思路
每个丑数一定是之前的某个丑数通过×2或×3或×5得来的。
第一个丑数为1
分别用下标ptr2，ptr3，ptr5来标记分别×2，×3，×5后得到的值大于当前队列中最大丑数的丑数在队列中的位置。
比如初始阶段队列中只有丑数1， 而1×2 1×3 1×5都大于当前队列中最大丑数1，所以ptr2，ptr3，ptr5初始值均为1在队列中的位置0.
每次往队列中加入新的丑数时，更新对应ptr2，ptr3和ptr5的值
### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        if (!n) return 0;
        vector<int> vec = {1};
        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;
        for (int i = 1; i <= n; ++i) {
            if (vec[ptr2] * 2 == vec.back()) ptr2++;
            if (vec[ptr3] * 3 == vec.back()) ptr3++;
            if (vec[ptr5] * 5 == vec.back()) ptr5++;
            vec.push_back(min(vec[ptr5] * 5, min(vec[ptr2] * 2, vec[ptr3] * 3)));
        }
        return vec[n-1];
    }
};
```