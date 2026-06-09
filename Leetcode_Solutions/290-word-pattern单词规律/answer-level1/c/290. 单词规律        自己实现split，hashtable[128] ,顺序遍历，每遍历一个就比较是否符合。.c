### 解题思路
//每遍历一个字符，都比较是否符合了，所以之前记录的索引可以被覆盖掉
//hashtable 里只记录字符出现的最新的位置即可，或者记录任何一个位置即可。。

给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true


### 代码

```c
int mysplit(char** res, char* str, char c, int len){
    char * temp = strchr(str, c);
    int k = 0;
    
    if(len == 0) return 0;

    res[k++] = str;
    //有用例  aaa  dog cat, 后者长度不够的，所以加参数len限制
    //用例里面，aa  dog dog dog 认为是false的， 所以此处最后一个没有分割也会对比失败
    while (temp && k < len) {
        *temp++ = '\0';
        res[k++] = temp;
        temp = strchr(temp, c);
    }
    return k;
}


bool wordPattern(char * pattern, char * str){
    int i = 0,len;
    int ht[128] = {0};

    len = strlen(pattern);
    if (pattern == NULL || str == NULL || len == 0)
        return false;

    char ** res = malloc(len * sizeof(char *));
    char c = ' ';
    
    if(mysplit(res, str, c, len) != len)
        return false;
    ht[pattern[0]] = 1;
    for (i = 1; i< len; i++) {
        if(ht[pattern[i]] != 0) {
            if(strcmp(res[i], res[ht[pattern[i]] - 1]))
                return false;
        }else{
            if(!strcmp(res[i], res[i-1]))
                return false;
        }
        //每次遍历都比较是否符合了，所以之前记录的索引可以被覆盖掉
        ht[pattern[i]] = i + 1;
    }

    return true;
}
```