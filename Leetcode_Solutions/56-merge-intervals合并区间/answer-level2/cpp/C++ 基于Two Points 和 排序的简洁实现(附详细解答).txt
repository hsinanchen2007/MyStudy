### 有用的双指针 (*^▽^*)
&emsp;**这种在数组空间上进行各种操作的题目，我一般喜欢利用双指针进行解决。**  
&emsp; 这题比较困难的地方在于各种边界情况的判定及其操作，以及如何快速有效的进行合并。
&emsp; 双指针在解决这类问题的时候总有着很清晰的思路，我们首先要减少冗余，复杂的情况，因此**排序**应该是自然而然的想法。我们先设双指针，第一个$save$用于保留和扩展，另一个$scan$用于扫描。
&emsp; 因为排完序之后我们对于左边界就不需要考虑了，因此我们还剩三种情况(X代表一个常数)：
- $eg:\overbrace{[1, 3]}^{save} , \overbrace{[4, 5]}^{scan}$,这种是最简单的**不相交**情况，**因此我们的$save$指针所指向的数组可以直接压入$ans$数组**,然后将$save$移动到$scan$指针处：$[1,3],\overbrace{[4, 5]}^{save} , \overbrace{[X, X]}^{scan}$
- $eg:\overbrace{[1, 4]}^{save} , \overbrace{[2, 3]}^{scan}$,这种是**被包含**的情况，因此我们不需要操作$save$指针，**$scan$指针继续往后移动**:$\overbrace{[1, 4]}^{save} , [2, 3], \overbrace{[X, X]}^{scan}$
- $eg:\overbrace{[1, 4]}^{save} , \overbrace{[3, 5]}^{scan}$,这种是里面唯一有一点点复杂的情况，即我们需要对于$save$指针指向的数组进行**扩展**，所以我们修改$\overbrace{[1, 4]}^{save} \rightarrow \overbrace{[1, 5]}^{save}$,然后将$scan$指针移向下一个，也就是这样:$\overbrace{[1, 5]}^{save} , [3, 5], \overbrace{[X, X]}^{scan}$

&emsp;现在思路非常简单了，只需要考虑一些**细节**上的问题:
①：排序二维数组，便于后续讨论
②：分情况进行讨论，对与双指针进行操作
③：最后一种特殊情况的处理(也就是$scan$指针移动到最后，但是还是没有压入数组中，需要特殊处理)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        \\ initialize 
        int u = 0, v = 0;
        vector<vector<int>> ans;
        \\ 思路①
        std::sort(intervals.begin(), intervals.end());
        \\ 思路②
        while (v < intervals.size()) { 
            if (intervals[v][0] > intervals[u][1]) {
                ans.emplace_back(intervals[u]);
                u = v;
            } else if (intervals[v][1] <= intervals[u][1]) {
                ++ v;
            } else {
                intervals[u][1] = intervals[v][1];
                ++ v;
            }
        }
        \\ 思路③
        ans.emplace_back(intervals[u]);
        return ans;
    }
};
```