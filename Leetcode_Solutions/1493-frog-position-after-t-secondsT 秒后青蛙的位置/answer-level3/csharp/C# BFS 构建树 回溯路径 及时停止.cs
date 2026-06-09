### 解题思路

##### 1. 题目概述：T秒后青蛙的位置

##### 2. 思路：
   - 特征：模型是一个树,要在 T 步内从起始位置到目标位置;走过的路径,每个分叉路口都要计算概率;
   - 方案：用 BFS 的方式,搜索最短路径,T 步内找不到,或者说 T 步走到了更远的地方,那么概率为 0;其余情况则依次计算每个路径下分叉路口的选择概率;
   - 结果：做不到,就是 0;做到了就是概率的乘积

##### 3. 知识点：树 BFS 数学

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp []
public class Solution {
        public double FrogPosition(int n, int[][] edges, int t, int target)
        {
            var rootToChildDic = new Dictionary<int, List<int>>(n);
            foreach (var edgeItem in edges)
            {
                var numArray = new int[] { edgeItem[0], edgeItem[1] };
                var small = numArray.Min();
                var bigger = numArray.Max();

                if (!rootToChildDic.ContainsKey(small))
                    rootToChildDic[small] = new List<int>();

                rootToChildDic[small].Add(bigger);
            }

            var visited = new int[n + 1];
            var queue = new Queue<int>();
            queue.Enqueue(1);
            var isFind = false;
            var calc = -1;
            while (queue.Any())
            {
                calc++;
                if (calc > t)
                {
                    isFind = false;
                    break;
                }

                var newQueue = new Queue<int>();
                while (queue.Any())
                {
                    var curItem = queue.Dequeue();
                    if (curItem == target)
                    {
                        if (rootToChildDic.ContainsKey(curItem) && calc != t)
                            isFind = false;
                        else
                            isFind = true;

                        break;
                    }

                    if (!rootToChildDic.ContainsKey(curItem)) continue;

                    foreach (var newPos in rootToChildDic[curItem])
                    {
                        visited[newPos] = curItem;
                        newQueue.Enqueue(newPos);
                    }
                }

                if (isFind)
                    break;

                if (newQueue.Any())
                    queue = newQueue;
            }

            if (!isFind) return 0;

            var path = new List<int>();
            var tValue = target;
            while(visited[tValue] != 0)
            {
                tValue = visited[tValue];
                path.Add(tValue);
            }

            var forReturn = 1.0;
            for (var i = 0; i < path.Count; i++)
                forReturn *= 1.0 / rootToChildDic[path[i]].Count;

            return forReturn;
        }
}
```