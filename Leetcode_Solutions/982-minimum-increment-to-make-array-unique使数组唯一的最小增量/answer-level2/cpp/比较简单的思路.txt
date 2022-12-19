### 解题思路
1、将数组排序
2、只需使后一个元素比前一个元素大1即可
### 代码

```cpp
class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A)
    {
        if (A.size() == 0) return 0;
        //将数组排序
        sort(A.begin(), A.end());
        //记录move操作的次数
        int count = 0;
        //遍历数组，使其后一个比前一个大1即可，若已大1，不变
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i+1] <= A[i])
            {
                count = count + A[i] + 1 - A[i+1];
                A[i+1] = A[i] + 1; 
            }
        }
        return count;
    }
};
```