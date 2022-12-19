### 解题思路
二分查找。
默认定位最中间，根据最中间的值判断当前值是在峰值的左边还是右边。把计算范围的左边界或右边界改掉，重新计算中点。
### 代码

```csharp
public class Solution {
    public int PeakIndexInMountainArray(int[] A) {
        int middle = A.Length / 2;
        int max = A.Length;
        int min = 0;
        while (A[middle - 1] > A[middle] || A[middle] < A[middle + 1])
        {
            if (A[middle - 1] > A[middle])
            {
                max = middle;
                middle = middle - (max - min) / 2;
            }
            else
            {
                min = middle;
                middle = middle + (max - min) / 2;
            }
        }
        return middle;
        
    }

    
}
```