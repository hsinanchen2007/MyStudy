C#解法，使用LINQ内置函数Intersect即可~

```csharp
public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        return nums1.Intersect(nums2).ToArray();
    }
}
```

**运行结果:**

执行用时: `272 ms`, 在所有 csharp 提交中击败了`100.00%`的用户

本人 `dotNET匠人`完成的 C#刷遍LeetCode面试题系列文章传送门:

<https://www.cnblogs.com/enjoy233/p/csharp_leetcode_series_1.html>




