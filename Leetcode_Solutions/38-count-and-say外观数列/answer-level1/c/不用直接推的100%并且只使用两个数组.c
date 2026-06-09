
```
我看见评论很多的人看不懂题目，我讲一下
第一行是                                            1
第二行是读第一行的数字并且把字符
的个数的写在前面，因为字符只有一
个，因此第二行是                                     11（第一个数是上一行的字符1的个数，后面是把上一行的字符写出来，因为是1，所以第二位数字是1）
因为第二行的字符1的个数是2所以第三行
是                                                  21（上一行的个数 + 字符）
不过要记住是相邻的个数
```
```
#define Len 4500
char * countAndSay(int n){
    char *pre, *arr, val = '0';
    int len = 1, fi = 1, i, counter, sit;
    pre = (char *)malloc(sizeof(char) * Len);
    arr = (char *)malloc(sizeof(char) * Len);
    // 以上是创数组
    pre[0] = '1';
    pre[1] = '\0';
    if(n ==  1)
       return pre;
    for (len = 2; len <= n; len++)
    {
        val = pre[0]; //pre是记录前面的的情况
        sit = 0;
        counter = 0;//counter是用来记录相同的字符的个数的
        for (i = 0; i < fi; )
        {
            if(pre[i] == val)//如果遇见相同的counter进行加一
            {
                counter++;
                i++;//遍历下一位
            }
            else
            {
                arr[sit++] = counter + '0'; // 先把个数进行放入，并且使用arr数组进行记录。counter + '0'是进行数字转化的字符用来存储。
                arr[sit++] = val;//再把字符放入
                counter = 0;
                val = pre[i];
            }
        }
        arr[sit++] = counter + '0';
        arr[sit++] = val;
        fi = sit;
        arr[sit] = '\0'; // 字符串进行封尾。**
        strcpy(pre,sit);
    }
    return pre;
}
```




