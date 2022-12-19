### 解题思路
1.核心思想：
1）**重复数组与转换后的单调递增序列的差值是最小的移动次数**
假设有重复序列X，Y，Z，其和为 X+Y+Z ；
单调递增后变为(X+n)+(Y+m)+(Z+l) = X+Y+Z+6（操作次数：n+m+l = 6） 。**那么操作次数究竟如何分配并不重要**
2）**关键是找到原始数组和与单调递增序列和的差值，因此问题转化为求单调递增序列**

原始数组转为为单调递增序列：
1）单调递增栈：
将元素从小到大排序后，将i元素压栈，如果i+1的元素 <=栈顶元素，则A[i+1] = A[i]+1,同时将A[i+1]入栈，并计算累计差值；

2）简化单调栈为最大值更新：因为每次i+1与i比，i都是栈顶元素，实际上除栈顶的元素以外，其他元素是没有用的。因此使用1个premax表示栈顶元素即可，可节省内存空间



### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {

        sort(A.begin(), A.end());

        int premax = 0;
        int count = 0;
        for (int i = 0; i < A.size();i++){
            if (i == 0){
                premax = A[i];
            }else{
                if(A[i]<=premax){
                    count += premax - A[i] + 1;
                    A[i] = premax + 1;
                }
                premax = A[i];

            }
        }

        return count;
    }
};
```