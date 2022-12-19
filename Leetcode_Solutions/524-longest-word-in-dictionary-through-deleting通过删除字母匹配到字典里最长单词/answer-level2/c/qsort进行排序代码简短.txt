### 解题思路
对d数组进行排序，先根据长度进行排序（长的放在前面），如果长度相同则进行字典序的排序把小的排在前面。在根据题目的要求进行选择符合要求的段落。


### 代码

```c
int cmp(const void * a, const void * b)
{
    int val;
    char * c = *(char **)a;
    char * d = *(char **)b;
    val = strlen(d) - strlen(c);//长得排在前面
    if(val == 0)//长度相同的则进行字典序小的排序。
        return strcmp(c,d);
    return val;
}
char * findLongestWord(char * s, char ** d, int dSize){
    qsort(d, dSize, sizeof(char *), cmp);//进心行排序
    char* str; 
    int i, ri = 0;
    int b = 0, b1 = 0, len = 0, len1 = 0;
    len = strlen(s);
    for(i = 0; i < dSize; i++)
    {
        b = b1 = 0;
        len1 = strlen(d[i]);
        while(b < len && b1 < len1)
        {
            if(s[b] == d[i][b1])//进行匹配
                b1++;
            b++;
        }
        if(b1 == len1)//匹配成功则结束
        {
            str = (char *)malloc(sizeof(char) * (len1 + 2));
            strcpy(str,d[i]);
            return str;
        }
    }
    return "";
}
```