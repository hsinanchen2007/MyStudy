### 解题思路
先将负数变为正数，再使用快排

### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        //将A先按照绝对值大小排序，再平方
        int i = 0;
        for(i = 0; i < A.size(); i++) {
            A[i] = abs(A[i]);
        }
        QuickSort(A, 0, A.size() - 1);
        
        for(i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }
        return A;        
    }

    void QuickSort(vector<int>& A, int low, int high) {
        //快排
        if(low < high) {
            int pivotpos = Partition(A, low, high);
            QuickSort(A, low, pivotpos - 1);
            QuickSort(A, pivotpos + 1, high);
        }
    }

    int Partition(vector<int>& A, int low, int high) {
        //划分操作
        int pivot = A[low];
        while(low < high) {
            while(low < high && A[high] >= pivot)
                --high;
            A[low] = A[high];
            while(low < high && A[low] <= pivot)
                ++low;
            A[high] = A[low]; 
        }
        A[low] = pivot;
        return low;
    }
};
```