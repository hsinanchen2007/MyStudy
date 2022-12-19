**思路1：** 遍历子串并对比，在haystack子串长度大于等于needle长度的情况下，进行haystack子串和needle对比。
```
public int StrStr(string haystack, string needle)
        {
            if (needle == "")
            {
                return 0;
            }

            //提前存下两个string的长度，避免后面反复计算长度的时间消耗
            int haystackLength = haystack.Length;
            int needleLength = needle.Length;
            //needle的长度不应该大于haystack
            if (needleLength > haystackLength)
            {
                return -1;
            }

            for (int i = 0; i < haystackLength; i++)
            {
                if (haystack[i] == needle[0])
                {
                    //haystack剩余的子串长度不该大于needle的长度
                    if (needleLength > haystackLength - i)
                    {
                        return -1;
                    }
                    else
                    {
                        if (haystack.Substring(i, needleLength).Equals(needle))
                        {
                            return i;
                        }
                    }
                }
            }

            return -1;
        }
```

![image.png](https://pic.leetcode-cn.com/e73f97ca56d1c5f54bd5ca378d6246238ff585c91bbe89e586a2fe1f40145998-image.png)
