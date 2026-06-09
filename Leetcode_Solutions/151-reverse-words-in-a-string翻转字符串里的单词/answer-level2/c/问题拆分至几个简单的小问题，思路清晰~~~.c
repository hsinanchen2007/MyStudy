### 解题思路
2020-4-10：C
原址操作~~~
问题：1.首尾出现空格
					 2.单词中间出现多个连续空格
					 3.单词进行翻转
解决方案：
						1.去除首部空格
						2.整体翻转，尾部空格转为首部空格
						3.去除首部空格
						4.去除单词中多个空格的情况
						5.当前首尾无空格，中间空格不重复，利用空格个数可以判断单词个数（单词数比空格数多一），锁定单词位置，进行局部翻转
						6.注意处理最后一个单词，因为结束时没有空格作为单词的终止标志

### 代码

```c
#include <string.h>

char * reverseWords(char * s){
    int len = strlen(s);
    int count = 0;
    int flag = 0;//标记位
    char temp;
    int start;

    //首部空格去除
    for (int i = 0;i < len;i++)
    {
        if (s[i] != ' ')
        {
            s[count] = s[i];
            flag = 1;
            count++;
        }
        else
        {
            if (flag == 1)
            {
                s[count] = s[i];
                count++;
            }
        }
    }
    s[count] = '\0';

    //整体翻转
    len = strlen(s);
    for (int i = 0;i < len / 2;i++)
    {
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }

    //去掉现在头部的空格（原尾部）
    flag = 0;
    count = 0;
    for (int i = 0;i < len;i++)
    {
        if (s[i] != ' ')
        {
            s[count] = s[i];
            flag = 1;
            count++;
        }
        else
        {
            if (flag == 1)
            {
                s[count] = s[i];
                count++;
            }
        }
    }
    s[count] = '\0';

    //处理单词中间多余的空格
    len = strlen(s);
    flag = 0; //重复使用flag,用于标记是否多个空格重复
    count = 0;
    for (int i = 0;i < len;i++)
    {
        if (s[i] == ' ')
        {
            if (flag == 0)
            {
                s[count] = s[i];
                flag = 1;
                count++;
            }
        }
        else
        {
            s[count] = s[i];
            flag = 0;
            count++;
        }
    }
    s[count] = '\0';

    //局部翻转
    //此时中间的空格仅仅只剩下一个
    start = 0;
    len = strlen(s);
    for (int i = 0;i < len;i++)
    {
        if (s[i] == ' ')
        {   
            for (int j = start;j < (i + start) / 2;j++)
            {
                temp = s[j];
                s[j] = s[i - 1 - (j - start)];
                s[i - 1 - (j - start)] = temp;
            }
            start = i + 1;
        }
    }
    //处理一下尾部情况
    for (int i = start;i < (len + start) / 2;i++)
    {
        temp = s[i];
        s[i] = s[len - 1 - (i - start)];
        s[len - 1 - (i - start)] = temp;
    }

    return s;
}
```