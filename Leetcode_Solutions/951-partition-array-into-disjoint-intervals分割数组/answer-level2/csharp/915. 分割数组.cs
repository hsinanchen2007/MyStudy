### 解题思路
C# O(N) 维护每个节点左边最大值和右边最小值，第一个左边最大节点小于此节点右边最小节点，即为所求；

### 代码

```csharp
public class Solution {
    public int PartitionDisjoint(int[] A) {
        var leftMax = new int[A.Length];
        var rightMin = new int[A.Length];
        leftMax[0] = A[0];
        rightMin[A.Length - 1] = A[A.Length - 1];
        for (int index = 1; index < A.Length; index++)
        {
            leftMax[index] = Math.Max(leftMax[index - 1], A[index]);
            rightMin[A.Length - 1 - index] = Math.Min(rightMin[A.Length - index], A[A.Length - 1 - index]);
        }

        for (int index = 0; index < A.Length - 1; index++)
        {
            if (leftMax[index] <= rightMin[index + 1])
            {
                return index + 1;
            }
        }

        return -1;
    }
}
```