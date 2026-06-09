太闲的话就看代码吧。。
```
class Solution {
public:

    template<typename T>
    void Insert_Sort(T A[], int N)
    {
        T tmp;
        int right;
        for (int p = 1; p < N; p++)
        {
            tmp = A[p];
            for (right = p; right > 0 && A[right - 1] > tmp; right--)
            {
                A[right] = A[right - 1]; //若被比较的元素A[left]大于new_item.则左移。
            }
            A[right] = tmp;
        }
    }
    template<typename T>
    inline void swap(T* a, T* b)
    {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }
    template<typename T>
    T Median3(T A[], int left, int right)
    {
        int mid = (left + right)/2;
        if (A[left] > A[mid])
            swap<T>(&A[left], &A[mid]);
        if (A[left] > A[right])
            swap<T>(&A[left], &A[right]);
        if (A[mid] > A[right])
            swap<T>(&A[right], &A[mid]);
        swap<T>(&A[mid], &A[right - 1]);
        return A[right - 1];
    }

    template<typename T>
    void Quicksort(T A[], int left, int right)
    {
        int cutoff = 4;
        if (cutoff <= right - left) 
        {
            int pivot = Median3<int>(A, left, right);
            int i = left;
            int j = right - 1;
            while (true)
            {
                while (A[++i] < pivot) {}
                while (A[--j] > pivot) {}
                if (i < j)
                    swap<T>(&A[i], &A[j]);
                else
                    break;
            }
            swap<T>(&A[i], &A[right - 1]);
            Quicksort<T>(A, left, i - 1);
            Quicksort<T>(A, i + 1, right);
        }
        else
        {
            Insert_Sort<T>(A + left, right - left + 1);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int* arr = &nums[0];
        int len = nums.size();
        Quicksort<int>(arr, 0, len-1);
        return nums[len-k];
    }
};
```
`
