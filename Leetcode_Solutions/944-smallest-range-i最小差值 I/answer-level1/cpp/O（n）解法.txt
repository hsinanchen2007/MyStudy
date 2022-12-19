```cpp
    int smallestRangeI(vector<int>& A, int K) {
        int Max = A[0], Min = A[0];

        for(int x: A)
        {
            Max = max(Max, x);
            Min = min(Min, x);
        }

        return max(0, Max - Min - 2*K);
    }
```