### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int Trap(int[] height) {
         if (height.Length < 3) return 0;
        var lefts = new int[height.Length];
        var rights = new int[height.Length];
        for (int index = 1; index < height.Length; index++)
        {
            lefts[index] = Math.Max(
                lefts[index - 1],
                height[index - 1]);

            rights[height.Length - index - 1] = Math.Max(
                rights[height.Length - index],
                height[height.Length - index]);
        }

        var result = 0;
        for (int index = 0; index < height.Length; index++)
        {
            result += Math.Max(
                0, // 即使没接住水，也不应该减少水
                Math.Min(lefts[index], rights[index]) - height[index]);
        }

        return result;
    }
}

```