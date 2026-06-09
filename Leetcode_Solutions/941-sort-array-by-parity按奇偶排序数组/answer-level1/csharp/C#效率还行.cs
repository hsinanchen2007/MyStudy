大概思路就是：从前边开始遍历，遇到奇数就与尾部的偶数交换
记录好本次交换的偶数的下标，下次交换直接从这个往前找
```
public int[] SortArrayByParity(int[] A) {
        int s = 0;
        for (int i = 0; i < A.Count() - s; i++)
        {
            if(A[i] % 2 != 0)
            {
                for (int j = A.Count() - 1 - s; j > i; j--)
                {
                    if (A[j] % 2 == 0)
                    {
                        int temp = A[i];
                        A[i] = A[A.Count() - 1 - s];
                        A[A.Count() - 1 - s] = temp;
                        s++;
                        break;
                    }
                    else
                    {
                        s++;
                    }
                }
            }
        }
        return A;
    }
```
