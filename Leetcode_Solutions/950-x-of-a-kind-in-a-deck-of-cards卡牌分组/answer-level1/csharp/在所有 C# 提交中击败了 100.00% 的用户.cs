优化要点
```yaml
1.if(deck.Length <= 1) return false;
2if (minCount== 1) return false;
```

3.寻找数字最小出现次数minCount
4.只计算1次minCount的所有公约数，储存为数组minList。遍历其他数字对minList的余数是否为0。

```
        public bool HasGroupsSizeX(int[] deck)
        {
            if(deck.Length <= 1)
            {
                return false;
            }
            Dictionary<int, int> d = new Dictionary<int, int>();
            for(int i = 0; i < deck.Length; i++)
            {
                if(d.ContainsKey(deck[i]))
                {
                    d[deck[i]]++;
                }
                else
                {
                    d[deck[i]] = 1;
                }
            }
            int minCount = d.Values.ToArray().Min();
            if (minCount == 1) return false;

            List<int> minList = new List<int>();
            int last = 2;
            while(minCount != 1)
            {
                if (minCount % last == 0)
                {
                    minList.Add(last);
                    minCount /= last;
                    last = 2;
                }
                else
                {
                    last++;
                }
            }

            foreach(var i in d)
            {
                bool right = false;
                foreach(var j in minList)
                {
                    if (i.Value % j == 0)
                    {
                        right = true;
                        break;
                    }
                }
                if(!right)
                {
                    return false;
                }
            }
            return true;
        }
```
