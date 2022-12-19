这道题解法有三种：
方法1：从后往前逐个拷贝单词到另一个数组中，需要使用额外数组空间N。
方法2：像镜像一样，先反转整个字符串，然后逐个反转每个单词，最后去除头部空格，中间空格以及尾部空格。
方法3：使用栈，从后往前将单词入栈，然后顺序出栈即可，同方法1一样，需要使用额外辅助空间。

下面的代码时方法2，先反转整个字符串，然后反转每个单词，最后去空格。
代码逻辑不是很复杂，但是边界情况写代码的时候需要特别注意。
```

/*
 *  特殊情况：参数为空或者长度小于1
 *  方法1：从后往前逐个拷贝单词到另一个数组
 *  方法2：反转整个字符串，然后反转每个单词
 *  方法3： 从后往前应该使用栈
 */

void swap(char *a,  char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void reverseWord(char *s, int first, int end)
{
    if (first == end)
        return;
    while(first < end)
        swap(s+(first++), s+(end--));
    return;   
}

char * reverseWords(char * s){
    int i, j, first, last,len,c;
    char *p, clast;
    
    //参数为空或者长度为0返回
    if (!s || strlen(s) < 1)
        return s;
    
    //反转字符串
    len = strlen(s);
    
    for (i = 0, j = len - 1; i < j;)
    {
        if (s[i] != s[j])
            swap(s+(i++), s+(j--));
        else
        {
            i++; j--;
        }   
    }
             
    //反转每个单词
    last = first = 0;
    while (1)
    {
        while(first < len && s[first] == ' ')first++;             
        if (first >= len)
            break;
        else
        {
            last = first;
            while(last < len && s[last] != ' ')last++;
            reverseWord(s, first, last - 1);
        }
        if (last >= len)
            break;
        first = last;
    }
        
    //去除开头空格
    i = 0;
    while(i < len && s[i] == ' ')
    {
        len--;
        s++;
    }   
                 
    if (len < 0)
        return s;

    //删除中间多余空格
    for (i = 0, j = 0, c = 0; i < len-1; i++)
    {
        while (i < len - 1 && s[i] == ' ' && s[i] == s[i+1])
        {
            c++; i++;
        }
        
        if (c && i < len - 1 && s[i+1] != ' ')
        {
            i++;
            while(i < len && s[i] != ' ')
            {
                swap(s+i-c, s+i);
                i++;
            }
            i--;
        }
    }

    //去除末尾空格
    len = strlen(s);
    while(len > 0 && s[len-1] == ' ')
    {
        s[len-1] = '\0';
        len--;
    }
    return s; 
}


```
