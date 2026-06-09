### 解题思路
BFS c#

### 代码

```csharp
public class Solution
    {
        private Dictionary<int, int> key = new Dictionary<int, int>();
        public int MaxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes)
        {
            Queue<int> vs = new Queue<int>();
            for (int i = 0; i < initialBoxes.Length; i++)
            {
                vs.Enqueue(initialBoxes[i]);
            }
            int count = 0;
            int end = 0;
            while (vs.Count>end) {
                var cb = vs.Dequeue();
                if (status[cb] == 1 || key.ContainsKey(cb))
                {
                    end = 0;
                    count += candies[cb];
                    foreach (var item in containedBoxes[cb])
                    {
                        vs.Enqueue(item);
                    }
                    foreach (var item in keys[cb])
                    {
                        if (!key.ContainsKey(item))
                        {
                            key.Add(item, 0);
                        }
                    }
                }
                else {
                    vs.Enqueue(cb);
                    end += 1;
                }
            }
            return count;
        }
    }
```