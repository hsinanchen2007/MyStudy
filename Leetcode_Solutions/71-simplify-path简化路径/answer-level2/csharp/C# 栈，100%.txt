![图片1.png](https://pic.leetcode-cn.com/1961300ec087c51634cf97ab90459d868f461ade1f12ca3bc01bb77010512a7d-%E5%9B%BE%E7%89%871.png)
```
            Stack<string> s = new Stack<string>();

            string[] spiltArr = path.Split('/');
            for (int i = 0; i < spiltArr.Length; i++)
            {
                if (spiltArr[i] == "")
                {
                    continue;
                }

                if (spiltArr[i] == "..")
                {
                    if (s.Count > 0)
                    {
                        s.Pop();
                    }
                }
                else if (spiltArr[i] != ".")
                {
                    s.Push(spiltArr[i]);
                }
            }

            if (s.Count != 0)
            {
                StringBuilder sb = new StringBuilder();
                while (s.Count != 0)
                {
                    sb.Insert(0, s.Pop());
                    sb.Insert(0, "/");
                }
                return sb.ToString();
            }
            else
            {
                return "/";
            }
```

