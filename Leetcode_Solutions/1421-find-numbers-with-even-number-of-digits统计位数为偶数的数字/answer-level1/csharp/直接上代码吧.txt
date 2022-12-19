### 解题思路


### 代码

```csharp
public class Solution {
    public int FindNumbers(int[] nums) {
        int r=0;
        foreach(var i in nums)
        {
            if(i.ToString().Length%2==0)r++;
        }
        return r;
    }
}
```