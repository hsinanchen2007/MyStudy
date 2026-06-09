```
public static string CountAndSay(int n)
        {
            string res = "1";
            if (n==1)
            {
                return res;
            }
            for (int i = 1; i < n; i++)
            {
                int Count = 0;//计算单个字母总数
                Stack st = new Stack();//记录当前字母
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < res.Length; j++)
                {
                    if (j==0)
                    {
                        st.Push(res[0]);
                        Count += 1;
                    }
                    else if ((char)st.Peek()==res[j])
                    {
                        Count += 1;
                    }
                    else
                    {
                            sb.Append(Count == 0 ? "1" : Count.ToString() + st.Pop());
                            st.Push(res[j]);
                            Count = 1;
                    }
                    if (j==res.Length-1)
                    {
                        sb.Append(Count == 0 ? "1" : Count.ToString() + st.Pop());
                    }
                }
                res = sb.ToString();
            }
            return res;
        }
```
