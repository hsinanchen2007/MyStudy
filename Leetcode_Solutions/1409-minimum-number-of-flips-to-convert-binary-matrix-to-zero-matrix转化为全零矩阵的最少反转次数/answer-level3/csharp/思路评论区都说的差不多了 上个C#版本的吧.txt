```
public class Solution
    {
        private Dictionary<int, string> dic = new Dictionary<int, string>();
        private Dictionary<string, int> dic1 = new Dictionary<string, int>();
        public int MinFlips(int[][] mat)
        {
            if (mat.Length == 0) {
                return -1;
            }
            StringBuilder sb = new StringBuilder();
            int count = 1;
            int len = mat.Length;
            int wid = mat[0].Length;
            for (int i = 0; i < mat.Length; i++)
            {
                for (int j = 0; j < mat[0].Length; j++)
                {
                    dic.Add( count, i + "," + j);
                    dic1.Add(i + "," + j, 0);
                    if (mat[i][j] == 1) {
                        sb.Append(count);
                    }
                    count++;
                }
            }
            if (sb.ToString() == "") { return 0; }
            Stack<int> stack = new Stack<int>();
            for (int i = 1; i <Math.Pow(2,len*wid); i++)
            {
                var temp = Convert.ToString(i, 2);
                var str = check(temp);
                if (str == sb.ToString()) {
                    var t = temp.Where(x => x == '1').ToList();
                    stack.Push(t.Count);
                }
            }
            return (stack.Count==0)?-1:stack.Min();
          
        }
        public string check(string str) {
            StringBuilder s = new StringBuilder();
            for (int i = 0; i < str.Length; i++)
            {
                s.Append(str[str.Length - 1 - i]);
            }
            str = s.ToString();
            for (int i = 1; i <= str.Length; i++)
            {
                if (str[i-1] == '1') {
                    if (dic1.ContainsKey(dic[i]))
                    {
                        dic1[dic[i]] += 1;
                    }
                    int x =Convert.ToInt32(dic[i].Split(',')[0]);
                    int y = Convert.ToInt32(dic[i].Split(',')[1]);
                    if (dic1.ContainsKey((x + 1) + "," + (y))) {
                        dic1[(x + 1) + "," + (y)] += 1;
                    }
                    if (dic1.ContainsKey((x - 1) + "," + (y)))
                    {
                        dic1[(x - 1) + "," + (y)] += 1;
                    }
                    if (dic1.ContainsKey((x) + "," + (y+1)))
                    {
                        dic1[(x) + "," + (y + 1)] += 1;
                    }
                    if (dic1.ContainsKey((x) + "," + (y-1)))
                    {
                        dic1[(x) + "," + (y - 1)] += 1;
                    }
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= dic.Count; i++)
            {
                if (dic1[dic[i]] % 2 == 1) {
                    sb.Append(i);
                    dic1[dic[i]] = 0;
                }
            }
            return sb.ToString();
        }

      

    }
```
![image.png](https://pic.leetcode-cn.com/b4ad6de2002a0e81b274e1189d1b69d4dba1ade371c09e9cbb783d0d868eeccd-image.png)
