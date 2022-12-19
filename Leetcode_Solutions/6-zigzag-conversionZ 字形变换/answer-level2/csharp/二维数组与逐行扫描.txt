做客户端做久了，看见图形式的问题，第一反应就是二维数组
# 二维数组
![z.jpg](https://pic.leetcode-cn.com/e566a329f3bc97a69fb67c2e6260f6e1591cbb623247e617a3264b48f3b31dcb-z.jpg)
按照字符串顺序把字符顺序的存在二维数组里。然后再根据行列读取二维数组里的字符，进行拼接，则得到最后的结果。
二维数组的列数怎么确定？进一步分析，可以看做一个三角形的两条边，多次重复连接得到的N字形。
![z1.jpg](https://pic.leetcode-cn.com/fc286464520de9665354638b56be45185c337840691ffcb04b0866c2d00ed351-z1.jpg)
这样通过计算有多少个三角形，再加上多出来的列则为总的列数。
那二维数组中的哪个位置要存放s中的字符呢？
通过图表总结出，当列数是行数的整数倍，或者 列数对行数取余+当前的行数 和 行数减1 相等的时候，需要进行赋值。
附上完整代码和注释一起来看下：
```
    public string Convert(string s, int numRows)
    {
        // 只有一行的时候，直接放回字符串
        if (numRows == 1)
        {
            return s;
        }

        // 每一个三角形两边 |/ 有多少个字符
        int single = numRows + numRows - 2;
        // 有多少个三角形
        int count = (numRows - 1) * (s.Length / single);

        // 是否有余数
        int left = s.Length % single;
        if (left > 0)
        {
            count += 1;
            //  如果余数大于行数
            if (left > numRows)
            {
                count += left - numRows;
            }
        }


        char[][] content = new char[count][];
        int index = 0;
        for (int i = 0; i < count; i++)
        {
            content[i] = new char[numRows];
            for (int j = 0; j < numRows; j++)
            {
                // 是行数的整数倍或者 列数取余+行数== numRows - 1
                if (i % (numRows - 1) == 0 || i % (numRows - 1) + j == (numRows - 1))
                {
                    if (index < s.Length)
                    {
                        content[i][j] = s[index];
                        index++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (j % (numRows - 1) == 0 || j % (numRows - 1) + i == (numRows - 1))
                {
                    if (content[j][i] != '\0')
                    {
                        sb.Append(content[j][i]);
                    }
                }
            }
        }
        return sb.ToString();
    }
```

然后提交，测试。ok。
就是耗时和内存都不咋理想。去看看其他高手的题解学习学习吧。
看完官方题解的第一种方式，顿时感觉自己特别的傻，犯了经验主义的错误。没有多角度的去思考问题和找解答方法。官方的这个解答巧妙而且代码很精简啊。
那么就按照官方的逐行扫描方案，用C# 实现以下。
只贴出代码，思路可以看看官方的题解就ok了。
```
    public string Convert2(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        List<List<char>> rows = new List<List<char>>();
        for (int i = 0; i < s.Length && i < numRows; i++)
        {
            rows.Add(new List<char>());
        }
        bool isdown = false;
        int row = 0;
        foreach (var c in s)
        {
            rows[row].Add(c);
            if (row == 0 || row == numRows - 1)
            {
                isdown = !isdown;
            }
            row += isdown ? 1 : -1;
        }

        StringBuilder sb = new StringBuilder();
        foreach (var l in rows)
        {
            sb.Append(new string(l.ToArray()));
        }

        return sb.ToString();
    }
```
提交，测试，ok。然而耗时和内存并没有很优，只是复杂度上很优秀。
不过还是觉得官方的思路很nice！
