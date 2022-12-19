### 解题思路
该题解题思路参考了官方题解的第一种方法，解决思路如下：
* 入参检查
* 判断替换后字符串的长度一定小于原字符串的长度，因此分配与原字符串长度相等的字符数组
* 循环遍历原数组，并判断s[i+2]出的元素是否为'#',并按照题目规则进行替换
* 返回替换结果

本题的时间复杂度为O(N)，空间复杂度为O(N)。

### 代码

```c
char * freqAlphabets(char * s){
    //入参检查
    if(!s)
    {
        return NULL;
    }

    //分配并初始化数组
    int len = strlen(s);
    char *result = (char*)malloc(sizeof(char)*len);
    memset(result,0,sizeof(char)*len);

    //循环遍历原数组，并替换字符串
    int k =0;
    for(int i=0; i<strlen(s); i++)
    {
        if(((i+2)<strlen(s)) && (s[i+2] == '#'))
        {
            result[k] = (s[i]-'0')*10+(s[i+1]-'1')+'a';
            k++;
            i+=2;
        }
        else
        {
            result[k] = s[i] - '1' + 'a';
            k++;
        }
    }
    return result;
}
```