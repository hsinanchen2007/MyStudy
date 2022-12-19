### 解题思路
倒着遍历一遍 保留当前右边最大值 挨个替换掉

### 代码

```csharp
public class Solution {
    public int[] ReplaceElements(int[] arr) {
        if(arr == null) return arr;
        int max = -1;
        for(int i = arr.Length - 1; i >= 0; i--)
        {
            int c = max;
            if(arr[i] > max)
                max = arr[i];
            arr[i] = c;
        }
        return arr;
    }
}
```