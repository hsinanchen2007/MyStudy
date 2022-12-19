（1）首先要理解题目的意思。
     比如说，你只认识0——9这十个数字，而且不知道有十进制这种表示数字的方法。当别人问你这样一串数字（比如“11122”）是什么时，你就会说是“三个一和两个二”连起来的。
所以，“11122”的下一位就是“3(个)1和2(个)2”，也就是“3122”.
（2）方法。
     要想得到当前的字符串是什么，必须通过解读上一个字符串，而要想得到下一个字符串，必须解读当前字符串，所以想到了递归。
（3）代码
```
        public string CountAndSay(int n)
                {   //n=1时，直接返回1；
                    if (n == 1)
                        return "1";
                    //递归，通过第n-1个字符串获取第n个
                    string newString = CountAndSay(n - 1);
                    StringBuilder builder = new StringBuilder();
                    //获取字符串的第一个元素为比较对象
                    char begin = newString[0];
                    //count用来计数，拿第一个字符作为比较对象，比较的时候至少有一个匹配，所以count从1 开始计数。
                    int count = 1;
                    for (int i = 1; i < newString.Length; i++)
                    {   
                        
                        if (newString[i] == begin)
                        {
                            count++;
                        }
                        else
                        {
                            builder.Append("" + count + begin);
                            begin = newString[i];  //newString[i]把当做比较对象
                            count = 1;//重新开始计数
                        }
                    }
                    //最后一个字符
                    if (begin == newString[(newString.Length - 1)])
                    {
                        builder.Append("" + count + begin);
                    }
                    return builder.ToString();
                }
```
