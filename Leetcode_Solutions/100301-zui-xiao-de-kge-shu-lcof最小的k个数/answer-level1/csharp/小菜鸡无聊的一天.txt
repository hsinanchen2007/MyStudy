### 解题思路
今天这题没啥说的，我去瞅瞅别人家的代码，

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
            Array.Sort(arr);
            int[] retarr = new int[k];
            for (int i = 0; i < k; i++)
            {
                retarr[i] = arr[i];
            }
            return retarr;
    }
}
```