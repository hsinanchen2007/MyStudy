### 解题思路
排序

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
        Array.Sort(arr);
        int[] result = new int[k];
        for(int i=0;i<k;i++){
            result[i]=arr[i];
        }
        return result;
    }
}
```