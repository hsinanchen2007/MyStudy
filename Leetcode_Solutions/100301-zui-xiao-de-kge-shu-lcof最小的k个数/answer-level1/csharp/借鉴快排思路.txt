### 解题思路
如果面试遇到这个肯定不会让你直接排序。所以这里利用快排思路，进行分区。当然快排也有弊端，需要修改数组。如果数组也不许修改而且需要实现O(n)平均复杂度的话，需要维护一个大小为K的小顶堆，然后遍历数组往堆里添加元素，如果遍历的元素比堆顶元素大则替换，然后堆化维护小顶堆特性，遍历完数组后直接输出该小顶堆即可。

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