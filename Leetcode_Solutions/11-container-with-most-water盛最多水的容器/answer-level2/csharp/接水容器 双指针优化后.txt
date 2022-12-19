### 解题思路
之前简单地用双指针遍历整个数组，发现结果并不理想。参考他人思路后改出132ms执行时间。主要考虑到了因为求得是面积最大值 所以从宽最大开始寻找，一个指针在最左，一个指针在最右向中间找最大面积。若左边高则右边指针向左一格要比左边指针向右损失小，最终会在中间汇合且max记录最大值

### 代码

```csharp
public class Solution {
   public int MaxArea(int[] height)
        {
            int max = 0;
            int len = height.Length;
            int i = 0;
            int j = len - 1;
            while(i < j)
            {
             max = Math.Max((j-i) * Math.Min(height[i], height[j]) , max);
             if(height[i]>height[j])
              j--;   
             else
              i++;
            }
            return max;
         }
}
```