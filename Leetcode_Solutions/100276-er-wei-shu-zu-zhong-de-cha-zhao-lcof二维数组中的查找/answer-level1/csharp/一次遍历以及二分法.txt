### 解题思路
一次遍历

### 代码

```csharp
public bool FindNumberIn2DArray(int[][] matrix, int target) {
        if(matrix == null || matrix.Length == 0 || matrix[0].Length == 0)
        {
            return false;
        }

        int i = 0;
        int j = matrix[0].Length - 1;
        while(i < matrix.Length && i >= 0 && j>= 0 &&  j < matrix[0].Length)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }else if(matrix[i][j] < target)
            {
                i++;
            }else
            {
                j--;
            }
        }

        return false;
        }
```

### 解题思路
二分查找

### 代码

```csharp
public class Solution {
    public bool FindNumberIn2DArray(int[][] matrix, int target) {
        if(matrix == null || matrix.Length == 0 || matrix[0].Length == 0)
        {
            return false;
        }

        int lastSmallIndex = GetLastSmallIndex(matrix, target);
        if(lastSmallIndex == -1)
        {
            return false;
        }

        for(int i = 0; i <= lastSmallIndex; i++)
        {
            if(BinarySearch(matrix[i], target) != -1)
            {
                return true;
            }
        }

        return false;
    }

    private int GetLastSmallIndex(int[][] matrix, int target)
    {
        int left = 0;
        int right = matrix.Length - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] <= target)
            {
                if(mid + 1 > right || matrix[mid + 1][0] > target)
                {
                    return mid;
                }
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return -1;
    }

    private int BinarySearch(int[] nums, int target)
    {
        int left = 0;
        int right = nums.Length - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }else if(nums[mid] < target)
            {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
}
```