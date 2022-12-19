### 解题思路
因为至少含有两个数，所以判断序列一定在`target/2+1`以内。
初始化右浮标为`target/2+1`，左浮标为右浮标-1，之后开始循环判断。
* 如果区间内序列和等于`target`，则把序列加入结果集中，右浮标减一
* 如果区间内序列和小于`target`，则右浮标减一
* 如果区间内序列和大于`target`，则左浮标减一
* 当左浮标减到0时结束循环
### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
            List<int[]> ans = new List<int[]>();
            int right = target / 2 + 1, left = right - 1;
            while (left > 0)
            {
                int sum = (right - left + 1) * (right + left) / 2;
                if (sum == target)
                {
                    int[] temp = new int[right - left + 1];
                    for (int i = 0; i < temp.Length; i++)
                    {
                        temp[i] = left + i;
                    }
                    ans.Add(temp);
                    right--;
                }
                if (sum > target)
                {
                    right--;
                }
                if (sum < target)
                {
                    left--;
                }
            }
            ans.Reverse();
            return ans.ToArray();
    }
}
```