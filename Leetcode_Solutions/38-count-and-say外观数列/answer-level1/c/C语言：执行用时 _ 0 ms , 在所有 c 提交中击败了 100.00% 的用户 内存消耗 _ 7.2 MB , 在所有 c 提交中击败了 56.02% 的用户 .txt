```
void trans(char* in_str,char* out_str)
{
    int length = strlen(in_str);
    int i,j=0,flag = 0;
    int count = 1;
    for (i = 0; i <length ; i++)
    {
        if (in_str[i] == in_str[i+1])
        {
            count++;
        }
        else
        {
            flag = 1;
        }
        if (flag == 1)
        {
            out_str[j] = count + '0';
            out_str[j+1] = in_str[i];
            out_str[j+2] = '\0';
            j = j + 2;
            count = 1;
            flag = 0;
        }
    }
    //从2开始
}

char * countAndSay(int n){
    char*  out_str = (char*)malloc(1024*6);
    char*  save_str = (char*)malloc(1024*6);
    int i,j;
    out_str[0] = '1';
    out_str[1] = '\0';
    save_str[0] = '\0';
    if (strlen(out_str) == 1)
    {
        save_str[0] = '1';
        save_str[1] = '\0';  
    }
    for (i = 1;i<n;i++)
    {
        trans(out_str,save_str);
        memcpy(out_str,save_str,strlen(save_str)+1);
    }

    return save_str;
}
```
