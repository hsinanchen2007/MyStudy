### 解题思路

类似于归并排序的合并数组 但这里没有临时数组，A空间足够，是合并到A
从右向左比较两个数组，将较大的数放置到数组A的m+n-1位置到0位置

### 代码

```cpp
class Solution {
public:

    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int pa = m - 1;
        int pb = n - 1;
        int p = m + n - 1;

        while (pa >= 0 && pb >= 0)
        {
            if (A.at(pa) >= B.at(pb))
            {
                A.at(p--) = A.at(pa--);
            }
            else
            {
                A.at(p--) = B.at(pb--);
            }
        }

        while (pb >= 0)
        {
            A.at(p--) = B.at(pb--);
        }
    }
};
```