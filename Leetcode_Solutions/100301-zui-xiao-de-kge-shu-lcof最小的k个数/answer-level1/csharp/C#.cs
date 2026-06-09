### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
        int[] result = new int[k];
        if(arr == null || k <= 0 || k > result.Length)
        {
            return result;
        }
        int start = 0;
        int end = arr.Length - 1;
        int index = Partition(arr, start, end);
        while(index != k - 1)
        {
            if(index > k - 1)
            {
                end = index - 1;
                index = Partition(arr, 0, end);
            }else{
                start = index + 1;
                index = Partition(arr, start, end);
            }
        }

        for(int i = 0; i < k; i++)
        {
            result[i] = arr[i];
        }
       
       return result;
    }

    private int Partition(int[] arr, int left, int right)
    {
        int target = arr[right];
        int i = left;
        int j = left;
        while(j < right)
        {
            if (arr[j] < target)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
            }
            j++;
        }

        arr[right] = arr[i];
        arr[i] = target;
        return i;
    }
}
```