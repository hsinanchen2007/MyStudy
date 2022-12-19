### 解题思路
该题与剑指offer中的字符替换属于同一类型，解题思路如下：
* 入参检查字符串是否为空
* 计算将'.'替换为'[.]'的数组长度
* 从头遍历原数组，遇到字符'.'进行替换
* 返回结果

本题的时间复杂度为O(N),空间复杂度为O(N)

### 代码

```c
char * defangIPaddr(char * address)
{
    //入参检查
    if(address == NULL)
    {
        return NULL;
    }
    //IP地址的格式中仅有4个'.'
    int len = strlen(address) + 4*2;
    char *result = (char*)malloc(sizeof(char)*len);
    memset(result,0,sizeof(char)*len);

    int j = 0;
    for(int i = 0;i<strlen(address);i++)
    {
        if(address[i] == '.')
        {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        }
        else
        {
            result[j++] = address[i];
        }
    }
    return result;
}
```