### 解题思路
这里本应该使用比较简单速度较快的排序方法，但是想起来前几天学了**桶排序**，于是就尝试着做了一下。
桶排序 (Bucket sort)或所谓的箱排序，是一个排序算法，工作的原理是将数组分到有限数量的桶子里。每个桶子再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）。桶排序是鸽巢排序的一种归纳结果。当要被排序的数组内的数值是均匀分配的时候，桶排序使用线性时间（Θ（n））。但桶排序并不是 比较排序，他不受到 O(n log n) 下限的影响。

**代码思路：**
        1、先找到追到最大最小的值，（假设最大max，最小min）
        2、计算需要几个桶来放数据：(max - min) / arr.Length + 1。
        3、然后将需要排序的数值一一对应放到各个所属范围的桶里面，
        4、然后把每个桶里面的数值进行基本排序，
        5、最后把排序后的数值按次序拿出来
### 代码

```csharp
public class Solution {
    public int[] SortArray(int[] nums) {
            /*桶排序：
                先找到追到最大最小的值，（假设最大max，最小min）
                桶数的计算：(max - min) / arr.Length + 1。
                然后将需要排序的数值一一对应放到各个所属范围的桶里面，
                然后把每个桶里面的数值进行基本排序，最后把排序后的数值按次序拿出来
             */
            List<int> numList = new List<int>();
            int min = nums.Min();
            int max = nums.Max();
            // 计算桶的数量
            int b_num = (max - min) / nums.Length + 1;
            // 定义桶
            List<int>[] buckets = new List<int>[b_num];
            // 初始化桶
            for(int i = 0;i<b_num;i++)
            {
                buckets[i] = new List<int>();
            }
            //分配待排序的数到各个桶里
            for(int i = 0;i<nums.Length;i++)
            {
                int index = (nums[i] - min) / nums.Length;
                buckets[index].Add(nums[i]);
            }
            //最后把各个桶里的数据拿出
            for (int i = 0; i < b_num; i++)
            {
                buckets[i].Sort();
                for (int j = 0; j < buckets[i].Count; j++)
                {
                    numList.Add(buckets[i][j]);
                }
            }
            int[] arr = numList.ToArray();
            return arr;
    }
}
```