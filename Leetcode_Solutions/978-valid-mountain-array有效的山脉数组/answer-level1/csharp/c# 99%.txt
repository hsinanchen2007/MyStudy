看下面
妙在统计Lenght 与 计数器i 的数量，如果== 。说明走到了尽头，避免了03212这种反复出现的山脉。
```
public bool ValidMountainArray(int[] A)
        {
            int N = A.Length;
            int i = 0;
            while (i + 1 < N && A[i] < A[i + 1])
                i++;
            if (i == 0 || i == N - 1)
                return false;
            while (i + 1 < N && A[i] > A[i + 1])
                i ++;
            if (i == N - 1)
                return true;
            else
                return false;

        }
```
