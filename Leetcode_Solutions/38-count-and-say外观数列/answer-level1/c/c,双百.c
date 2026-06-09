没什么好说的，直接暴力寻解，至于为啥申请8000大小，别问，问就是试出来的。
（其实我后来试了一下，5000就够了，代码贴进来懒得改了，逃~
char * countAndSay(int n){
    char *re;
    char alpht[] ="123456789"; 
    char temp[8000] = "";
    int count;
    re = (char *)malloc(sizeof(char)*8000);
    memset(re,'\0',sizeof(char)*8000);
    re[0] = '1';
    
    int i,j,k,top;//从re里往temp统计，然后把temp复制到re里，在进行下一波处理
    for(i = 0;i < n-1;i++)
    {
        top = 0;
        for(j = 0;j < 8000;)
        {
            k = j + 1;
            while(k < 8000 )
            {
                if(re[k] == '\0')
                    break;
                if(re[k] == re[j])
                    k++;
                else
                {
                    break;
                }
            }
            count = k-j;
            temp[top] = alpht[count-1];
            top++;
            temp[top] = re[j];
            top++;
            j = k;
            if(re[k] == '\0')
                break;
        }
        memcpy(re,temp,sizeof(char)*8000);
        memset(temp,'\0',sizeof(char)*8000);
    }
    return re;
}