```
    public class Solution
    {
        private string bw;

        private Dictionary<string, List<string>> dic = new Dictionary<string, List<string>>();

   

        int flag = 0;
        public IList<IList<string>> FindLadders(string beginWord, string endWord, IList<string> wordList)
        {
            bw = beginWord;
            if (!wordList.Contains(bw)) { wordList.Add(bw); }
            if (!wordList.Contains(endWord)) { return new List<IList<string>>(); }
            
            for (int i = 0; i < wordList.Count; i++)   //将wordlist中的单词填充到字典中 按*ab形式为key
            {
                for (int j = 0; j < wordList[i].Length; j++)
                {
                    var temp = new StringBuilder();
                    for (int k = 0; k < wordList[i].Length; k++)
                    {
                        if (j == k)
                        {
                            temp.Append("*");
                        }
                        else { temp .Append (wordList[i][k]); }
                    }
                    if (dic.ContainsKey(temp.ToString()))
                    {
                        dic[temp.ToString()].Add(wordList[i]);
                    }
                    else
                    {
                        var list = new List<string>();
                        list.Add(wordList[i]);
                        dic.Add(temp.ToString(), list);
                    }
                }
            }
            Queue<help> q = new Queue<help>();//创建两个队列  将开始词语放入q以help类形式存入队列中 

            Queue<help> p = new Queue<help>();
            q.Enqueue(new help { val = endWord, parent = null });


            while (true)  
            {
                if (q.Count == 0 && p.Count == 0)
                {
                    return new List<IList<string>>();
                }
                if (q.Count != 0 && p.Count == 0)
                {
                    next(q, p);
                    if (flag == 1)//当flag==1时返回结果队列中带有目标单词的help对象列表。并通过help对象parent得到路径
                    {
                        return lhtores(p.Where(x => x.val == bw));                    
                    }
                    continue;
                }
                if (q.Count == 0 && p.Count != 0)
                {
                    next(p, q);
                    if (flag == 1)
                    {
                        return lhtores(q.Where(x => x.val == bw));
                    }
                    continue;
                }
            }
        }
        public List<IList<string>> lhtores(IEnumerable<help> list)
        {
            List<IList<string>> res = new List<IList<string>>();
            foreach (var item in list)
            {
                var tmp = new List<string>();
                add(tmp, item);
                res.Add(tmp);
            }
            return res;
        }

        public void add(List<string> vs, help node)
        {
            vs.Add(node.val);
            if (node.parent != null)
            {
                add(vs, node.parent);
            }
        }

        /// <summary>
        /// 将队列q中的元素循环取出并查询字典中可到达的点 存入队列p
        /// 然后将q中元素从字典中移除来保证不走重复的路
        /// 当检测到目标单词时flag=1
        /// </summary>
        /// <param name="queue"></param>
        /// <param name="p"></param>
        public void next(Queue<help> queue, Queue<help> p)
        {
            int count = queue.Count;
            for (int i = 0; i < count; i++)
            {
                var str = queue.Dequeue();
                for (int j = 0; j < str.val.Length; j++)
                {
                    var tmp = "";
                    for (int k = 0; k < str.val.Length; k++)
                    {
                        if (j == k)
                        {
                            tmp += "*";
                        }
                        else
                        {
                            tmp += str.val[k];
                        }
                    }
                    if (dic.ContainsKey(tmp))
                    {                 
                        foreach (var item in dic[tmp])
                        {
                            if (item == bw) { flag = 1; }        
                            if (item != str.val )
                            {
                                p.Enqueue(new help { val = item, parent = str });
                            }
                        }
                        if (str.val != bw)
                        {
                            dic[tmp].Remove(str.val);
                        }
                    }
                }
            }

        }
    }


    public class help
    {
        public string val { get; set; }
        public help parent { get; set; }
    }
```
有大佬看的话能修下车吗。 能跑出结果但是会超时。按BFS跑的为啥别人的不超时