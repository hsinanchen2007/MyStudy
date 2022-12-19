### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] arr) {
        var res = new List<IList<int>>();
        Array.Sort(arr);
        for (int i = 0; i < arr.Length - 2 && arr[i] < 1; i++)
            if (i == 0 || arr[i] != arr[i - 1])
                for (int l = i + 1, r = arr.Length - 1; l < r;){
                    int sum = arr[i] + arr[l] + arr[r];
                    if (sum == 0) res.Add(new int[] { arr[i], arr[l], arr[r] });
                    if (sum <= 0) while (l < r && arr[l] == arr[++l]) ;
                    if (sum >= 0) while (l < r && arr[r] == arr[--r]) ;
                }
        return res;
    }
}
```