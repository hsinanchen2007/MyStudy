跟课程表一代码一样的，
https://leetcode-cn.com/problems/course-schedule/solution/c-dfs-by-tan-lang-2/，
只是返回不同。

trueList 的 插入顺序是确保该树叶上满足条件的时候插入。
如对于树
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;|
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;&nbsp;2
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2
插入顺序为 2,1,0，就是题目要求的结果
```
        public int[] FindOrder(int numCourses, int[][] prerequisites)
        {
            IEnumerable<int> enumerable = Enumerable.Range(0, numCourses);
            //课程依赖列表
            List<int>[] list = enumerable.Select(c => new List<int>()).ToArray();
            foreach (int[] item in prerequisites)
            {
                list[item[0]].Add(item[1]);
            }
            //满足条件的列表
            var trueList = new HashSet<int>();
            for (int i = 0; i < numCourses; i++)
            {
                if (!DFS(trueList, new HashSet<int>(), list, i))
                {
                    return new int[0];
                }
            }
            return trueList.ToArray();
        }
    
        public bool DFS(HashSet<int> trueList, HashSet<int> used, List<int>[] list, int id)
        {
            if (trueList.Contains(id))
            {
                return true;
            }
            if (used.Contains(id))
            {
                return false;
            }
            else
            {
                used.Add(id);
            }

            foreach (int item in list[id])
            {
                if (DFS(trueList, used, list, item) == false)
                {
                    return false;
                }
            }
            trueList.Add(id);
            return true;
        }
```
