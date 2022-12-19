### 解题思路
求左右最大值

### 代码

```csharp
public class Solution {
    public int Trap(int[] height) {
        int[] leftMaxs = new int[height.Length];
        int[] rightMaxs = new int[height.Length];

        int leftMax = 0;
        int rightMax = 0;
        for(int i = 0; i < height.Length; i++)
        {
            leftMaxs[i] = leftMax;
            leftMax = Math.Max(height[i], leftMax);

            rightMaxs[height.Length - 1 - i] = rightMax;
            rightMax = Math.Max(height[height.Length - 1 - i], rightMax);
        }

        int water = 0;
        for(int i = 0; i < height.Length; i++)
        {
            int leftRightMaxMin = Math.Min(leftMaxs[i], rightMaxs[i]);

            if(leftRightMaxMin > height[i])
            {
                water += leftRightMaxMin - height[i];
            }
        }

        return water;
    }
}
```