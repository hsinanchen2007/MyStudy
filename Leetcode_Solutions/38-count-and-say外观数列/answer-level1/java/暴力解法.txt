# 笨蛋解法，耗时挺久的
创建一个大小为30的数组来存放列表，然后初始化数组的第一二两个元素为“1”，“11”；然后通过循环来遍历数组前一个元素中的每一个字符，使用一个计数器，遇到相邻元素相同则加1，遇到不同元素则把之前计算出的元素个数写入字符串，最后遍历结束后将该字符串写入数组
```
public static String countAndSay(int n)
    {
        String string[] = new String[30];
        string[0] = "1";
        string[1] = "11";
        String s = "";  //  用于存放即将放入数组中的新元素
        int count = 1;  //  用于计数相邻有几个相等的数
//        初始化数组元素
        for(int i = 2; i < 30; i++)
        {
            for(int j = 0; j < string[i-1].length()-1; j++)
            {
                if (string[i-1].charAt(j) == string[i-1].charAt(j+1))
                {
                    count++;    //  当相邻元素相同时，计数器加1;
                }
                else {
                    s += String.valueOf(count) + string[i-1].charAt(j);
                    count = 1;
                }
            }
            s += String.valueOf(count) + string[i-1].charAt(string[i-1].length()-1);
            string[i] = s;
            s = "";
            count = 1;
        }
        return string[n-1];
    }
```

