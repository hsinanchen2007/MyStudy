### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   void quickSort(vector<int>& a, int low, int high)
    {
        if (low > high)
            return;

        int i = low;
        int j = high;
        int base = a[i];
        while(i < j)
        {
            while(i < j && base <= a[j])
                j--;
            if(i < j)
            {
                a[i] = a[j];
                i++;
            }
            while( i < j && a[i] <= base)
                i++;
            if(i < j)
            {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = base;
        quickSort(a, low, i - 1);
        quickSort(a, i + 1, high);
    }

    int minIncrementForUnique(vector<int>& A) {
        quickSort(A, 0, A.size() - 1);
        int move = 0;
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i] <= A[i - 1])
            {
                int gap = A[i - 1] - A[i];
                A[i] = A[i - 1] + 1;
                move += gap + 1;
            }
        }
        return move;
    }
};
```