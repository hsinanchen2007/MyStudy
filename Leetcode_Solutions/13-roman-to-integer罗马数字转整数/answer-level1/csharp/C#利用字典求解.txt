思路是利用字典，将所有特殊值添加进字典中
先对原字符串遍历求和，会发现我们将原本的特例如“IV”，“IX”等也加了上去，相当于我们的和求了两次特例的和
所以将负两倍的值添加进字典
接着遍历特例字典，如果字符串中包含特例字符串的值，就将它在第一次求和的基础上再加进去，即可求解。
代码如下所示：
public int RomanToInt(string s) {
        Dictionary<string, int> dic = new Dictionary<string, int>();  
            dic.Add("I", 1);
            dic.Add("V", 5);
            dic.Add("X", 10);
            dic.Add("L", 50);
            dic.Add("C",100);
            dic.Add("D", 500);
            dic.Add("M",1000);
            Dictionary<string, int> dicx = new Dictionary<string, int>();
            dicx.Add("IV", -2);
            dicx.Add("IX", -2);
            dicx.Add("XL", -20);
            dicx.Add("XC", -20);
            dicx.Add("CD", -200);
            dicx.Add("CM", -200);
            int result = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (dic.ContainsKey(s[i].ToString()))
                {
                    result += dic[s[i].ToString()];
                }
            }

            foreach (string key in dicx.Keys)
            {
                if (s.Contains(key))
                {
                    result += dicx[key];
                }
            }
            return result;


    }

