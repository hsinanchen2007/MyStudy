### 解题思路
1.遍历第一个字符串
2.如果第一个字符串中某个字符和第二个字符串首字节相等
3.通过while循环判断,是否从第一个开始相等到第二个字符串结束,都相等

### 代码

```c
int strStr(char * haystack, char * needle){
    
    int num = 0;
    int k = 0;
    int tmp = 0;
    int flag = 0;
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if(n_len <= 0)
        return 0;
    
    if(n_len > h_len)
        return -1;

   
    for(int i = 0;i< h_len;i++)
    {
        flag = 0;
        tmp = 0;
        num = 0;
        k = 0;
        if(haystack[i] == needle[k])
        {
            num = i;
            tmp = i;


            if(h_len - tmp < n_len)
                return -1;
            
                while(needle[k] != '\0'){
                    if(haystack[tmp++] != needle[k++])
                    {
                        flag =1;
                    }
                }

                if(flag == 0)
                    return num;

        } 

    }

    return -1;
    
}
```