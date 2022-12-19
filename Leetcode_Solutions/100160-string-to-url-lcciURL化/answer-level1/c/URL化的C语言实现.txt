### 解题思路
该题参考了别人的题解，解题思路如下：
* 入参检查字符串是否为空
* 遍历字符串，获取空格的个数
* 所有的空格都要替换为%20,即原长度要增加2
* 计算新字符串的长度
* 从后向前遍历原始字符串，将空格替换为%20,并将数组元素依次向后移动

本题的时间复杂度为O(N),空间复杂度为O(N)。

### 代码

```c
char* replaceSpaces(char* S, int length)
{
    //入参检查
    if(S == NULL)
    {
        return NULL;
    }
    
    //遍历字符串，获取空格的个数
    int num = 0;
    int i =0;
    for(int i = 0;i<length;i++)
    {
        if(S[i] == ' ')
        {
            num++;
        }
    }

    int newlen = length + num*2;
    int j = newlen - 1;
    for(i=length-1; i>=0 && i != j; i--)
    {
        if(S[i] == ' ')
        {
            S[j--] = '0';
            S[j--] = '2';
            S[j--] = '%';
        }
        else
        {
            S[j--] = S[i];
        }
    }
    S[newlen] = '\0';
    return S;
}
```