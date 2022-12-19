**基本思路：** 以数组中第一个string元素为基础，逐个取这个string的每个子字符，然后和后面的string元素的对应索引的子字符进行比对
```
public string LongestCommonPrefix(string[] strs)
        {
            if (strs.Length == 0)
            {
                return "";
            }

            string result = "";
            for (int i = 0; i < strs[0].Length; i++)
            {
                for (int j = 1; j < strs.Length; j++)
                {
                    if (i >= strs[j].Length || !strs[0][i].Equals(strs[j][i]))
                    {
                        return result;
                    }
                }
                //每次循环都需要通过substring跟新result,这一步比较耗时
                //可以用记录index的方式，在return之前计算result
                result = strs[0].Substring(0, i+1);
            }

            return result;
        }
```
