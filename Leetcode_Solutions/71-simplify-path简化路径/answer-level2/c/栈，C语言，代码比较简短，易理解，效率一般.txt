我们先把数组去掉'/'，把字符串放入一个二维的数组。再用两个指针进行便利这个二维数组，进行".."和"."的操作。最后剩下的字符进行连结。
希望对大家有帮助😁
```
#define LEN 1000
char * simplifyPath(char * path){
    char ** arr = (char **)malloc(sizeof(char*) * LEN);//创造二维数组
    char t[50];
    int len = strlen(path);
    char * return_arr = (char*)malloc(sizeof(char) * len+5);
    int le = 1, ri = 0,i;
    for(i = 1; i < len; i++)
    {
        if(path[i] == '/' || i == len - 1)
        {
            if(path[i] != '/' && i == len - 1)//遍历道最后的一个的判断。
                i = i + 1;
            if(i - le != 0)//如果不为0，复制到二维的数组
            {
                arr[ri] = (char *)malloc(sizeof(char) * 100);
                strncpy(arr[ri], path + le, i - le);
                arr[ri][i - le] = '\0';
                puts(arr[ri]);
                ri++;
            }
            le = i + 1;
            continue;
        }
    }
    le = 0;
    for(i = 0; i < ri; i++)
    {
        if(strcmp(arr[i],".") == 0)
            continue;
        if(strcmp(arr[i],"..") == 0)//如果为".."就返回到上一层
        {
            if(le > 0)
                le--;
            continue;
        }
        strcpy(t,arr[i]);//进行覆盖
        strcpy(arr[le],t);
        le++;
    }
    return_arr[0] = '\0';
    if(le == 0)
    {
        strcat(return_arr,"/");
        return return_arr;
    }
    for(i = 0; i < le; i++)//最后进行连结
    {
        strcat(return_arr,"/");
        puts(return_arr);
        strcat(return_arr,arr[i]);
    }
    return return_arr;
}
```
