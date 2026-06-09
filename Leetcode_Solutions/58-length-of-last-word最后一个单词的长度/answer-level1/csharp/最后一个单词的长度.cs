**思路1：** 利用C#现成类库中的split方法，但是要特别注意"a  "这种情况，不能直接取最后一个string数组元素。
```
public int LengthOfLastWord(string s)
        {
            string[] array = s.Split(' ');
            for (int i = array.Length - 1; i >= 0; i--)
            {
                if (!string.IsNullOrEmpty(array[i]))
                {
                    return array[i].Length;
                }
            }
            return 0;
        }
```


**思路2：** 一次遍历，从头开始遍历，计算沿路的每一个单词的长度并将结果更新为最新计算的单词长度，直到结尾(详情见代码及注释)。
```
public int LengthOfLastWord2(string s)
        {
            int result = 0;
            int currentIndex = 0;
            int stringLength = s.Length;

            while (currentIndex < stringLength)
            {
                int i = currentIndex;
                //获取单词的索引区间[currentIndex,i)
                for (; i < stringLength; i++)
                {
                    if (s[i] == ' ')
                    {
                        break;
                    }
                }
                //计算单词长度
                result = i - currentIndex;

                //获取下一个单词的起点索引
                while (i < stringLength && s[i] == ' ')
                {
                    i++;
                }
                currentIndex = i;
            }

            return result;
        }
```

![image.png](https://pic.leetcode-cn.com/b98e53b022bcd612211746351e2b2aae525c049de1d55868b51247482bbb56e3-image.png)
