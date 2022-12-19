本题的难度是 简单，但是我做下来感觉没有那么简单，或许是我太菜了吧。 

先说下，我原来的思路：

- 找到与`needle`字符串首字符相等的字符在`haystack`字符串当中首次出现的位置`position`
- 然后遍历`needle`字符串，逐个与`haystack`字符串在`postion`之后的字符进行比较遇到不同则返回-1
- 如果遍历之后没有返回，在跳出循环后返回`position`

具体代码如下：


```c []

int strStr(char * haystack, char * needle)
{
    int haylen = strlen(haystack);
    int needlelen = strlen(needle);
    
    
    if(needlelen == 0)
        return 0;
    
    if(needlelen > haylen)
        return -1;
    
    int position = 0;
    
    //int* positionlist = (int *)malloc(hyalen * sizeof(int));

    //找到与needle字符串首字符相等的字符在haystack字符串当中首次出现的位置
    while(position < haylen)
    {
        if(haystack[position] == needle[0])
        {
            break;
        }
        
        position++;
    }
    
    //遍历
    
    for(int i  = 0; i < needlelen; i++)
    {
        if(haystack[position + i] != needle[i])
            return -1;
    }
    
    return position;
}
```

很遗憾，这样写是有bug的，比如`needle`的首字符在`haystack`中重复出现，且能够匹配上的完整字符串并不是第一个，比如下面这个例子：

![bug](https://pic.leetcode-cn.com/21bc85a2df069274d3db1eb97f7cab9257b983ba7a69d090bf3d98b0f31b3ca3.png)

既然如此，后面就换了一种思路，索性开一个数组`positionlist`，把所有与`needle`首字符匹配的`position`都找出来并加以记录，后面再比较每个`position`开始的`needlelen`长度的字符串是否与`needle`相等，如果相等则返回当前的位置，都不想等的话在跳出循环后返回-1，具体代码如下：


```c []
//subString 子函数
char * subString(char * s, int startIndex, int endIndex)
{
/*
  s: 需要截取的字符串头指针变量
  startIndex: 截取起始索引
  endIndex: 截取终止索引
 */
    assert(endIndex >= startIndex);
    assert(s != NULL);

    int length = endIndex - startIndex;

    char *tmp = (char *)malloc(SHRT_MAX * sizeof(char));

    strncpy(tmp, s + startIndex, length);

    tmp[length] = '\0';

    return tmp;
}

int strStr(char * haystack, char * needle)
{
    int haylen = strlen(haystack);
    int needlelen = strlen(needle);
    
    
    if(needlelen == 0)
        return 0;
    
    if(needlelen > haylen)
        return -1;
    
    int position = 0;
    int positionIndex = 0;
    
    int* positionlist = (int *)malloc(haylen * sizeof(int));
    memset(positionlist, 0, sizeof(int) * haylen);
    //int positionlist[haylen];

    while(position < haylen)
    {
        if(haystack[position] == needle[0])
        {
            positionlist[positionIndex++] = position;
        }
        position++;
    }
    
    
    for(int j = 0; j < positionIndex; j++)
    {
        if(haylen - positionlist[j] < needlelen)
        {
            return -1;
        }
        else
        {
            char* tmp = subString(haystack, positionlist[j], positionlist[j] + needlelen);
            if(strcmp(tmp, needle) == 0)
            {
                return positionlist[j];
            }

        }

    }
    
    return -1;
    
}
```

