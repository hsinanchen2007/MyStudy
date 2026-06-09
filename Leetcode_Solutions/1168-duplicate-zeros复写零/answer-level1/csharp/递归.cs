### 解题思路
执行用时：536 ms
内存消耗：65.1 MB

刚刚学了递归，应用一下。
### 代码

```csharp
public class Solution {
    public void DuplicateZeros(int[] arr) {
    
     helper(arr,0, arr.Length - 1);
    
    }
    public void helper(int[] arr, int n,int length)
    {
        for (int i = n; i<= length; i++)
        {
            if (arr[i] == 0)
            {
                arr.Skip(0).Take(i+1).ToArray().CopyTo(arr, 0);
                arr.Skip(i).Take(length -i).ToArray().CopyTo(arr,i+1);
                helper(arr,i+2,arr.Length - 1);
                break;
            }
        }
    }
}
```