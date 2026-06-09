感觉考察递归,就写了个递归.
```
public string CountAndSay(int n)
{
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
```