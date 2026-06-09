
不太会说理论，简单说下代码逻辑和注意事项。

1、确认科目的依赖关系,结构如下
{
&nbsp;&nbsp;&nbsp;&nbsp;"0":[1,2],//科目0的先修课程为1，2
&nbsp;&nbsp;&nbsp;&nbsp;"1":[2]
}
最开始使用了Dictionary<int,List<int>>来保存，后来发现科目代码是给出的：0 到 numCourses，用List<int>[]性能更好。

2、使用trueList来保存已经确认可以全部学习的科目，避免重复遍历
3、used为树支上已经使用过的可能存在问题的数的列表

4、使用DFS
4-1、循环每个数，判断每个数下的依赖项是否满足条件
4-2、trueList 如果包含该数，表示遍历过，直接返回false。并且不往 used 中插入数，避免其他树支上重复用到同一个数的问题。
4-3、如果一个 used 中包含该数，并且truelist不包含，说明这条未遍历完的树支的上层中出现过该数，出现重复依赖，返回 false。否则，将该数插入 used 。
4-4、递归遍历，该数的依赖项。
4-5、在一个数和它的依赖项确认可以全部学习后，都要加入trueList。
4-6、全部数都返回true,则结果为true,只要有一个为false,则返回false。
```

        public bool CanFinish(int numCourses, int[][] prerequisites)
        {
            //科目的依赖关系
            List<int>[] list = Enumerable.Range(0, numCourses).Select(c => new List<int>()).ToArray();
            foreach (int[] item in prerequisites)
            {
                list[item[0]].Add(item[1]);
            }
            //可以全部学习的科目
            var trueList = new HashSet<int>();
            for (int i = 0; i < numCourses; i++)
            {
                if (!DFS(trueList, new HashSet<int>(), list, i))
                {
                    return false;
                }
            }
            return true;
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
