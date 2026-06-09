先排序
相邻的相等就对后面一个++，后面++之后会导致后面的数比前面的小，因此要把后面的调整到比前一个+1
```
public class MinIncrementForUniqueSolution
{
    public int MinIncrementForUnique(int[] A)
    {
        if (A.Length <= 1) return 0;
        Array.Sort(A);
        int ret = 0;
        for (int i = 1; i < A.Length; i++)
        {
            if (A[i] <= A[i-1])
            {
                ret += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return ret;
    }
}
```
