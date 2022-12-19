### 解题思路

##### 1. 题目概述：通知所有员工所需的时间

##### 2. 思路：
   - 特征：整个从属关系,就是一个颗树;树的节点值,就是通知直属下属所需的时间;叶子节点的值都是 0;保证全员都收到消息,就是从根到叶所有节点之和的最大值
   - 方案：利用 BFS 的方式遍历树,不断累积节点的值,到叶子节点的时候,判断是否耗时最长并做记录;
   - 结果：记录到所有叶子节点的和,其中最大的值,就是所求的解;

##### 3. 知识点：树 BFS

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public int NumOfMinutes(int n, int headID, int[] manager, int[] informTime)
        {
            var managerToStaff = new Dictionary<int, List<int>>(n);
            for (var i = 0; i < manager.Length; i++)
            {
                var mId = manager[i];
                if (!managerToStaff.ContainsKey(mId))
                    managerToStaff[mId] = new List<int>();

                managerToStaff[mId].Add(i);
            }

            var queue = new Queue<int[]>();
            queue.Enqueue(new int[] { headID, 0 });

            var sum = 0;
            while (queue.Any())
            {
                var curManager = queue.Dequeue();

                var time = informTime[curManager[0]] + curManager[1];
                if (informTime[curManager[0]] == 0)
                {
                    sum = Math.Max(sum, time);
                    continue;
                }

                if (managerToStaff.ContainsKey(curManager[0]))
                    foreach (var s in managerToStaff[curManager[0]])
                        queue.Enqueue(new int[] { s, time });
            }

            return sum;
        }
}
```