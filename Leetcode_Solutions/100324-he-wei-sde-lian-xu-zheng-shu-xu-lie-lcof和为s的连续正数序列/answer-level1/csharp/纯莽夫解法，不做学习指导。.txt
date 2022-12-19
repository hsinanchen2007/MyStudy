### 解题思路
连续正整数递增，递增区间为[1,中间数]。
为了避免进行小于等于的判断，这里将中间数加了2，可以只用做小于判断。

双循环进行递增运算，
递增和大于target值的，结束循环。
递增和等于target值的，生成数组，保存进动态数组里。

最后将动态数组转换为交错数组，进行返回。

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target)
        {

            ArrayList arrayList = new ArrayList();
            int centreNum = target / 2 + 2;

            for (int indexNum = 1; indexNum < centreNum; indexNum++)
            {
                int sum = 0;
                for (int num = indexNum; num < centreNum; num++)
                {
                    sum += num;
                    if (sum > target)
                    {
                        break;
                    }
                    if (sum == target)
                    {
                        int lengthNum = num - indexNum + 1;
                        int[] array = new int[lengthNum];
                        for (int nodeNum = 0; nodeNum < lengthNum; nodeNum++)
                        {
                            array[nodeNum] = indexNum + nodeNum;
                        }
                        arrayList.Add(array);
                    }
                }
            }

            int[][] grid = new int[arrayList.Count][];

            for (int i = 0; i < arrayList.Count; i++)
            {
                grid[i] = arrayList[i] as int[];
            }

            return grid;
        }
}
```