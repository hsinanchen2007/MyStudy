### 解题思路
1.发现所求的前缀是第一个元素的右边几个字符，设一个容器接收字符即可；
2.依次取出第一个字符串的每一个字符，依次与其他元素的相应位的字符进行比较；
3.比较时，记录相同结果出现的次数，可判断是否是所求的前缀字符；
4.两层循环，出现不满足相等条件时，两层循环均结束；
5.循环继续时，temp要归零；
6.返回值是指针，但定义一个数组，对数组操作会简单些；
7.填充数组，最后结束要加上'\0'.

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int i, temp, len = 0;
    char *pre;   
    if(strsSize <1)
        return "";
    len = strlen(strs[0]);
    char result[len + 1];
    pre = malloc(sizeof(char) * (len + 1));
    pre = result;
    while(strs[0][i] != '\0')
    {
        temp = 0;
        for(int j = 0;j < strsSize;j++)
        {
            if(strs[0][i] == strs[j][i])
                temp++;
            else               
                break;            
        }
        if(temp != strsSize)
            break;
        else
        {
            result[i] = strs[0][i];
            i++; 
        }
      
    } 
    result[i] = '\0';
    return pre;

}
```