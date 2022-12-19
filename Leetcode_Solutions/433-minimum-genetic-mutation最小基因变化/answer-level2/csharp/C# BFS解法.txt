### 思路
1.从start->end有多种路径（状态树），每变一个基因即为1个路径上的节点。
2.start中的8个字符，每个字符有ACGT四种可能，那么start[i]有剩余三种变化的可能。
所以第一次变化后会有8*3=24种字符串，变化后的新字符串，同理也会有这么多变化。
3.通过层序遍历各种变化，找到第一条变化路径满足从start->bank->end，经历过的层数即为解。
4.由于变化存在重复，需要记录已经访问过的字符串，否则会重复入队，永远无法清空队列。
5.套用BFS代码模板即可。


```
    public int MinMutation(string start, string end, string[] bank)
    {
        if (string.IsNullOrEmpty(start) 
            || string.IsNullOrEmpty(end) 
            || bank.Length == 0) return -1;
        if (bank.Contains(end) == false) return -1;

        int count = 0;
        Queue<string> queue = new Queue<string>();
        queue.Enqueue(start);
        ISet<string> visited = new HashSet<string>();
        while (queue.Count != 0)
        {
            int size = queue.Count;//当前层有多少个元素
            for (int i = 0; i < size; i++)
            {
                string current = queue.Dequeue();
                if (current == end) return count;
                for (int j = 0; j < start.Length; j++)
                {
                    char[] tmp = current.ToCharArray();
                    foreach (var c in "ACGT")
                    {
                        tmp[j] = c;
                        string str = new string(tmp);
                        if (visited.Contains(str) == false && bank.Contains(str))
                        {
                            visited.Add(str);
                            queue.Enqueue(str);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
```
