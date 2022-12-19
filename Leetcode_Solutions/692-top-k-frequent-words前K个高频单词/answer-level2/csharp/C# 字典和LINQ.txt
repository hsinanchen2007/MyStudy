```csharp
       // 字典
        public IList<string> TopKFrequent(string[] words, int k)
        {
            Dictionary<string, int> dic = new Dictionary<string, int>();

            foreach (var word in words)
            {
                dic[word] = dic.ContainsKey(word) ? dic[word] + 1 : 1;
            }

            var res = dic.OrderByDescending(s => s.Value).ThenBy(s => s.Key).Take(k).ToList();

            List<string> list = new List<string>();

            for (int i = 0; i < k; i++)
            {
                list.Add(res[i].Key);
            }


            return list;
        }

        // LINQ
        public IList<string> TopKFrequent2(string[] words, int k)
        {
            IList<string> list = new List<string>();
        
            // 以单个字符串为键分组
            words.GroupBy(x => x)
                // 创建一个匿名类, 存储键和重复的个数
                .Select(x => new {id = x, count = x.Count()})
                // 以个数升序排列
                .OrderByDescending(x => x.count)
                // 个数相同的情况下以匿名类的id也就是string字符串升序排列
                .ThenBy(x => x.id.Key)
                // 取前K个
                .Take(k)
                .ToList()
                .ForEach(x=>list.Add(x.id.Key));  
            
            return list;
        }
```
