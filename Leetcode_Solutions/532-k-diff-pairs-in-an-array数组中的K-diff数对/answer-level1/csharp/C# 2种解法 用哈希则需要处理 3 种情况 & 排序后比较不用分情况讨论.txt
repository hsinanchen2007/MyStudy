### 解题思路

##### 1. 题目概述：数组中的 k-diff 数对

##### 2. 思路：
   - 特征：相同的数字构成的是同一个数对;数值的取值范围很大,不适合一开始就申请足够的数组空间做统计;知道一个值,以及差值,那么目标值就是固定的了;
   - 方案：遍历数组做统计;再遍历统计结果,依据当前值判断目标值是否存在;不断累积;
   - 结果：统计结果汇总

##### 3. 知识点：数组 哈希表

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)

### 代码

```csharp []
public class Solution {
        public int FindPairs1(int[] nums, int k)
        {
            if (k < 0) return 0;

            var orderList = new Dictionary<int, int>(nums.Length);
            foreach (var numItem in nums)
            {
                if (!orderList.ContainsKey(numItem))
                    orderList[numItem] = 0;
                orderList[numItem]++;
            }

            if (k == 0)
                return orderList.Count(i => i.Value > 1);

            var forReturn = 0;
            foreach (var orderItem in orderList)
                if (orderList.ContainsKey(orderItem.Key + k))
                    forReturn++;

            return forReturn;
        }
}
```

### 解题思路
##### 1. 题目概述：数组中的 k-diff 数对

##### 2. 思路：
   - 特征：已知值和差值,期望值就是固定的;若序列有序,那么使用队列来处理,是个不错的选择;
   - 方案：将数组排序;遍历有序数组;每个元素都是要进队列的;进入队列之前,与队列的第一个元素做判断;差值太大,就丢弃;差值太小,就下一轮;满足要求,则统计
   - 结果：统计的值

##### 3. 知识点：数组 队列 哈希表

##### 4. 复杂度分析: 
   - 时间复杂度：O(nlogn)
   - 空间复杂度：O(n)

### 代码

```csharp解一 []
public class Solution {
        public int FindPairs(int[] nums, int k)
        {
            var orderList = nums.OrderBy(i => i).ToList();

            var recordStartSet = new HashSet<int>(nums.Length);
            var queueTemp = new Queue<int>(nums.Length);
            foreach (var item in orderList)
            {
                while (queueTemp.Any())
                {
                    var subValue = item - queueTemp.Peek();

                    if (subValue > k)
                        queueTemp.Dequeue();
                    else if (subValue == k)
                        recordStartSet.Add(queueTemp.Dequeue());
                    else
                        break;
                }

                queueTemp.Enqueue(item);
            }

            return recordStartSet.Count;
        }
}
```
```csharp解二 []
public class Solution {
        public int FindPairs(int[] nums, int k)
        {
            var orderList = nums.OrderBy(i => i).ToList();

            var recordStartSet = new HashSet<int>(nums.Length);
            var preIndex = 0;
            for (var i = 1; i < orderList.Count; i++)
            {
                while (preIndex < i)
                {
                    var subValue = orderList[i] - orderList[preIndex];

                    if (subValue > k)
                        preIndex++;
                    else if (subValue == k)
                        recordStartSet.Add(orderList[preIndex++]);
                    else
                        break;
                }
            }

            return recordStartSet.Count;
        }
}
```