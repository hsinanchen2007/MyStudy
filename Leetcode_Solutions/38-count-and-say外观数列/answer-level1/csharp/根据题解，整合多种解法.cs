//1 
public class Solution {
    public string CountAndSay(int n) {
         string str = "1";
            for (int i = 2; i <= n; i++)
            {
                StringBuilder stringBuilder = new StringBuilder();
                //取得要数的数
                char pre = str[0];
                int count = 1;
                //数 数的个数
                for (int j = 1; j < str.Length; j++)
                {
                    char c = str[j];
                    if (c == pre)
                    {
                        count++;
                    }
                    else
                    {
                        stringBuilder.Append(count).Append(pre);
                        pre = c;
                        count = 1;
                    }

                }
                stringBuilder.Append(count).Append(pre);
                str = stringBuilder.ToString();
            }
            return str;
    }
}

//2
public class Solution {
    public string CountAndSay(int n) {
       if (n <= 0)
            {
                return "";
            }
           string str = "1";
            for (int i = 2; i <= n; i++)
            {
                str = convert(str);
            }
            return str;
    }
    public string convert(string str)
        {
             StringBuilder ans = new StringBuilder();
            int count = 1;
            for (int i = 0; i < str.Length; i++)
            {
                if (i < str.Length - 1 && str[i] == str[i+1])
                {
                    count++;
                }
                else
                {
                    ans.Append(count).Append(str[i]);
                    count = 1;
                }
            }
            return ans.ToString();
        }
}



//3
public class Solution {
    public string CountAndSay(int n) {       
          return countHelper("1", n);
    }
    private static string countHelper(string str, int n)
        {
            if (n == 1) return str;
            else
            {
                //求下一个数
                StringBuilder stringBuilder = new StringBuilder();
                int i = 0;
                //一直读数
                while (i < str.Length)
                {
                    int count = 1;
                    //如果一直是同一个数
                    while (i < str.Length - 1 && str[i] == str[i+1])
                    {
                        count++;
                        i++;
                    }
                    //下一个数更新
                    stringBuilder.Append(count.ToString() + str[i]);
                    i++;
                }
                str = stringBuilder.ToString();
            }
            return countHelper(str, n - 1);
        }
}



//4
public class Solution {
    public string CountAndSay(int n) {       
             if (n == 1)
    {
        return "1";
    }
    else
    {
        string num = CountAndSay(n - 1);//上一个字符串
        string result = "";
        int count = 1;
        for (int i = 0; i < num.Length - 1; i++)
        {
            if (num[i] == num[i + 1])
            {
                count++;
            }
            else
            {
                result += count.ToString() + num[i];
                count = 1;
            }
        }
        return result + count.ToString() + num[num.Length - 1];//补充最后一个字符
    }


    }
   
}


//5
public class Solution {
    public string CountAndSay(int n) {       
          if (n == 1)
            {
                return "1";
            }
            LinkedList<int> queue = new LinkedList<int>();
            // 计数
            int count = 0;
            // 标记
            int temp;
            queue.AddLast(1);
            for (int i = 0; i < n - 1; i++)
            {
                temp = queue.First();
                int len = queue.Count();
                for (int j = 0; j < len; j++)
                {
                    // 取出一个元素
                    int poll = queue.First();
                    queue.RemoveFirst();

                    if (poll != temp)
                    {
                        queue.AddLast(count);
                        queue.AddLast(temp);
                        temp = poll;
                        // 因为已经取了一个,count自动加1
                        count = 1;
                    }
                    else
                    {
                        count++;
                    }
                }
                queue.AddLast(count);
                queue.AddLast(temp);
                count = 0;
            }

            StringBuilder sb = new StringBuilder();
            foreach (int integer in queue)
            {
                sb.Append(integer);
            }

            return sb.ToString();
    }
   
}
