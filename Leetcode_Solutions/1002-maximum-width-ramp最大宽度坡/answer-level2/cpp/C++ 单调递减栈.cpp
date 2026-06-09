根据题意需要找出最大宽度并且`A[i] <= A[j]`，很容易想到`i`需要从左往右，`j`从右往左遍历数组。
进一步思考，`A[i]`的值越小越容易得到最大宽度，同时还要考虑`i`尽可能的小。
到这里，可以想到利用单调递减栈:
1、正向扫描数组记录严格的单调递减`A[i]`的下标
2、反向扫描数组比较`A[j]`与栈顶元素`A[s.top()]`的值，如果满足条件，则弹出栈顶元素，不断循环直到栈为空

代码：
反向扫描数组时，对下标的边界情况可以做一下小小的优化
```c++
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;                               // 单调递减栈
        for (int i = 0; i < A.size(); i++) {
            if (s.empty() || A[i] < A[s.top()]) {   // 严格小于，相等的情况下肯定是i值更小得到的宽度最大
                s.emplace(i);
            }
        }

        int ans = 0;
        for (int j = A.size() - 1; j > ans; j--) {  // 这里有一点小优化，如果j<=ans，因为下标从0开始，后面都不需要再循环了
            while (!s.empty() && A[j] >= A[s.top()]) {
                ans = max(ans, j - s.top());
                s.pop();
            }
        }
        return ans;
    }
};
```
