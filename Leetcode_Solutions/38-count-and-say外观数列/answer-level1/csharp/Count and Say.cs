**思路1：** 将字符串拆分成多个子串，每个子串内都是相等的数字，然后对子串进行计算结果，最终拼接这些结果得出下一个次序的字符串。
如：1211-->1'2'11-->11'12'21-->111221。
```
public string CountAndSay(int n)
        {
            if (n == 1)
            {
                return "1";
            }

            int count = 1;
            StringBuilder result = new StringBuilder("1");
            while (++count <= n)
            {
                //如果对字符串操作拼接比较多可以使用StringBuilder，省内存
                StringBuilder newResult = new StringBuilder();
                for (int i = 0; i < result.Length;)
                {
                    char loopElement = result[i];
                    int j = i + 1;
                    for (; j < result.Length; j++)
                    {
                        if (!result[j].Equals(loopElement))
                        {
                            break;
                        }
                    }
                    //计算下一次序字符串
                    newResult = newResult.Append((j - i) + "" + loopElement);
                    i = j;
                }
                result = newResult;
            }

            return result.ToString();
        }
```

![image.png](https://pic.leetcode-cn.com/f46bd232e7b5854051902e075b7fdc1df4bf56091b3e46b908e2909f7484954c-image.png)
