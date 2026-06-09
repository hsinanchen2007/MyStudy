解析：
用到了一个小的技巧，创建一个bool数组,第一个指定为 true

true,false,false,false,false,true,false,false,true,false,false,false,false,true
截取从true，到true  的包含才算有效，
然后将当前的标记为true返回最后一个true证明刚好结束
 动态规划：
```
            int len = s.Length;
            bool[] f = new bool[len + 1];
            f[0] = true;
            for (int i = 1; i < len + 1; i++)
                for (int j = 0; j < i; j++)
                    if (f[j] && wordDict.Contains(s.Substring(j, i - j)))
                    {
                        f[i] = true;
                        break;
                    }
            return f[len];

        static void Main(string[] args)
        {
            List<string> s = new List<string>() { "apple","pen","apple" };
            Console.Write(WordBreak("applepenapple", s));
            Console.ReadKey(); 
        } 
```
