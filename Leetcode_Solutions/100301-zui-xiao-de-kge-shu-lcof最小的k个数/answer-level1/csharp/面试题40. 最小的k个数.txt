### 解题思路
C# 没有实现默认的优先队列，可以使用快速排序；

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
        return QuickSort(arr).Take(k).ToArray();
    }

    public static int[] QuickSort(int[] arr)
    {
        Part(arr, 0, arr.Length - 1);
        return arr;
    }

    public static void Part(int[] arr, int start, int end)
    {
        if (start >= end) return;
        int i = start, j = end;
        int pivot = arr[i];
        while (i < j)
        {
            while (i < j)
            {
                if (arr[j] <= pivot)
                {
                    arr[i] = arr[j];
                    break;
                }
                else
                {
                    j--;
                }
            }
            while (i < j)
            {
                if (arr[i] > pivot)
                {
                    arr[j] = arr[i];
                    break;
                }
                else
                {
                    i++;
                }
            }
        }

        arr[i] = pivot;
        Part(arr, start, i - 1);
        Part(arr, i + 1, end);
    }
}
```