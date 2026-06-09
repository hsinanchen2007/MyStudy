### 解题思路
因为是刚学的新人，很多都不会，强行自己做了N个函数来解这道题，hhh，就六个纪念，另外我看写C#的人都挺少的，写的我也都看不懂。就贴出来嘻嘻，其他新人可以共同进步，虽然很繁琐，但所有函数的目的我都写了，还有一些比较难看懂的操作。如果还看不懂就把代码贴到VS里就行了，里面都会介绍这个字段的功能

### 代码

```csharp
 public class Solution
    { 
        public  string GcdOfStrings(string str1, string str2)
        {
            int len1 = U(str1);
            int len2 = U(str2);
            int max;
            if (len1 > 0 && len2 > 0)
            {
                if ((str1.Length > len1) && (str2.Length > len2))
                {
                    if (zhengque(str1, len1) && zhengque(str2, len2) && CompareArray(c(fuzhishuzu(str2), 0, len2 - 1) , c(fuzhishuzu(str1), 0, len1 - 1)))
                    {
                        max = GetLargestCommonDivisor(str1.Length / len1, str2.Length / len2);
                        return String.Join("", (c(fuzhishuzu(str1), 0, max * len1 )));//把得到的数组串成没有空格的一串字符串然后输出，因为是题目要求
                    }
                    else
                        return "";
                }
                else if ((str1.Length == len1) && (str2.Length > len2))
                {
                    if (zhengque(str2, len2) && CompareArray(c(fuzhishuzu(str2), 0, len2 ), c(fuzhishuzu(str1), 0, str1.Length )))
                        return str1;
                    else
                        return "";
                }
                else if ((str2.Length == len2) && (str1.Length > len1))
                {
                    if (zhengque(str1, len1) && CompareArray(c(fuzhishuzu(str2), 0, str2.Length ), c(fuzhishuzu(str1), 0, len1 )))
                        return str2;
                    else
                        return "";
                }
                else if ((str2.Length == len2) && (str1.Length == len1))
                {
                    if (CompareArray(fuzhishuzu(str1), fuzhishuzu(str2)))
                        return str2;
                    else
                        return "";
                }

                else
                    return "";
            }
            else
                return "";
        }
        public static bool CompareArray(string[] bt1, string[] bt2)//验证两个数组是否相等
        {
            var len1 = bt1.Length;
            var len2 = bt2.Length;
            if (len1 != len2)
            {
                return false;
            }
            for (var i = 0; i < len1; i++)
            {
                if (bt1[i] != bt2[i])
                    return false;
            }
            return true;
        }
        public static string  []fuzhishuzu(string str)//把字符串每一个字符都分割到数组
        {
            string[] s = new string[str.Length];
            for (int j = 0; j < str.Length; j++)
            {
                s[j] = str[j].ToString();
            }
            return s;
        }
        public static bool zhengque(string str,int len
           )//确认是否有规律
        {
            string[] s = fuzhishuzu(str);
            
            List<int> list1 = new List<int>();
            list1.Add(0);


            for (int i = 0; i < (str.Length / len - 1); i++)
            { if (CompareArray(c(s, len * i, len * i + len), c(s, len * i + len, len * i + 2 * len)))
                    list1[0] = 2;
                else
                {
                    list1[0] = 1;
                    break;
                }
            }

            if (list1[0] == 2)
                return true;
            else
                return false;

        }

        public static string  []c(string []z, int x,int y)//得到一个数组的第几项到第几项
        {
           
            string[] g = new string [y-x];

            Array.Copy(z, x, g, 0, y-x);
            return g;
        }
       

        public static int  U(string str)//求出数组重复组块长度
    {
        List<int> list = new List<int>();
            list.Add(0);
             if (str.Length > 0)
            {
                for (int i = 1; i < str.Length/2+1; i++)
                {
                    
                    if ( CompareArray(c(fuzhishuzu(str), 0, i), c(fuzhishuzu(str), i,2*i)))
                    {
                        if (str.Length / i > 2)//防止FFFF0X的情况在i是2的时候就会停
                        {
                            if (str[i + 1] == str[2 * i + 1])
                            {
                                list[0] = i;
                                break;
                            }
                            else
                                continue;
                        }
                        else
                            list[0] = i;
                    }
                    else
                        list[0] = str.Length ;
                }
                
        }
         return list[0];
    }
        static int GetLargestCommonDivisor(int n1, int n2)//求最大公因数
        {
            int max = n1 > n2 ? n1 : n2;
            int min = n1 < n2 ? n1 : n2;
            int remainder;
            while (min != 0)
            {
                remainder = max % min;
                max = min;
                min = remainder;
            }
            return max;
        }
        

    }


```