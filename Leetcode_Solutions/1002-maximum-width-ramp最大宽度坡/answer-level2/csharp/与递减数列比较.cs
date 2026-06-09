### 解题思路
1、从数组头部开始构建递减数列。
2、从数组尾部开始与递减数列尾部最小的值比较，战胜递减数列元素越多，则有可能为最大宽度坡，与记录的最大宽度坡进行比较即可。时间复杂度o(N)。

### 代码

```csharp
public class Solution {
    public int MaxWidthRamp(int[] A) {
        int MaxWidth = 0;
        Stack<int> DeStack = new Stack<int>();

        if(A.Length != 0)
        {
            DeStack.Push(0);
        }

        for (int i = 1;i< A.Length;i++)
        {
            if(A[DeStack.Peek()]==0)
            {
                break;
            }
            if(A[DeStack.Peek()] > A[i])
            {
                DeStack.Push(i);
            }
        }

        for (int i = A.Length - 1; i > MaxWidth; i--)
        {
            while(DeStack.Count!=0)
            {
                if(A[i]>= A[DeStack.Peek()])
                {
                     int tmpWidth = i - DeStack.Pop();
                    if(MaxWidth<tmpWidth)
                    {
                        MaxWidth = tmpWidth;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return MaxWidth;
    }
}
```