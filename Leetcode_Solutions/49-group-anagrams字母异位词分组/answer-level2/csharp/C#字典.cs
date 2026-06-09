```csharp
        // 先遍历, 排序字符, 相等的放入字典中
        public IList<IList<string>> GroupAnagrams(string[] strs)
        {
            var res = new List<IList<string>>();
            var grp = new Dictionary<string, IList<string>>();

            // 遍历每一个字符串
            foreach (var str in strs)
            {
                // Concat:将指定字符串连接到此字符串的结尾
                // OrderBy 将char升序排列
                // rt是排序过的字母 eat -> aet
                string rt = String.Concat(str.OrderBy(ch => ch));

                // 放入字典中
                if (grp.ContainsKey(rt))
                {
                    grp[rt].Add(str);
                }
                else
                {
                    grp[rt] = new List<string>{str};
                }
            }

            foreach (var key in grp.Keys)
            {
                res.Add(grp[key]);
            }

            return res;
        }
```
