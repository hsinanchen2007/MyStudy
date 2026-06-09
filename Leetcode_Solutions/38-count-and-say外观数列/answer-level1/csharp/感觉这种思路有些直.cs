遍历字符，计数，只要下一个字符与当前的不相同，或者没有下一个，可写入该段结果，计数器归零。
```c#
public string CountAndSay(int n)
        {
            string rt = "";
            for (int i = 1; i <= n; i++)
            {
                if (i == 1)
                {
                    rt = "1";
                }
                else
                {
                    int count = 0;
                    string h = "";
                    for (int j = 0; j < rt.Length; j++)
                    {
                        count++;
                        var c = rt[j];
                        if (j + 1 == rt.Length|| rt[j + 1] != c)
                        {
                            h += $"{count}{c}";
                            count = 0;
                        }
                    }
                    rt = h;
                }
            }
            return rt;
        }
```
