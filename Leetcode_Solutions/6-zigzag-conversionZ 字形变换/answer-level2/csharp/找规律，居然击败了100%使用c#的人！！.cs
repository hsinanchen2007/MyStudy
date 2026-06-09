找规律，居然击败了100%使用c#的人！！

![Snipaste_2019-08-31_20-47-13.png](https://pic.leetcode-cn.com/67fb7fd28933423489101d222f26f791aee242d6085044d434ec25feef62a20d-Snipaste_2019-08-31_20-47-13.png)


注意特殊情况的处理。

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    public class Solution
    {
        public string Convert(string s, int numRows)
        {
            StringBuilder res = new StringBuilder(s);

            if(numRows == 1) { return res.ToString(); }

            if(s.Length < numRows) { return res.ToString(); }

            int step = 2 * numRows - 2;

            int k = 0;
            for(int i = 0; i < numRows; ++i)
            {
                int left = step - 2 * i;
                int right = 2 * i;

                int idx = i;
                res[k++] = s[idx];
                while (true)
                {
                    if(left != 0)
                    {
                        idx += left;
                        if (idx >= s.Length) break;
                        res[k++] = s[idx];
                    }
                    
                    if(right != 0)
                    {
                        idx += right;
                        if (idx >= s.Length) break;
                        res[k++] = s[idx];
                    }
                }
                
            }

            return res.ToString();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution a = new Solution();
            Console.WriteLine(a.Convert("0123456", 1)) ;
            Console.ReadLine();
        }
    }
    
}
```


