int isok(char * s1, char * s2 ) //检查s2 是否在s1中，不考虑空串
{
    //puts(s1);
    //puts(s2);
    int len_s1= strlen(s1);
    int len_s2=strlen(s2);
    if (len_s2>len_s1)return 0;
    int j=0;//s2的下标
    for(int i=0;i<len_s1;i++)
    {
        if(s1[i]==s2[j])j++;
        if(j==len_s2)
        {
            //printf("ok\n");
            return 1;
        }
    }
    //printf("not ok\n");
    return 0;
}

int cmp ( const void *a , const void *b )
{
return strcmp( *(char **)a , *(char **)b );
}

char * findLongestWord(char * s, char ** d, int dSize){
    qsort(d,dSize,sizeof(d[0]),cmp);
    //printf("after sort %s %s %s %s\n",d[0],d[1],d[2],d[3]);
    int max_len= 0;
    int j=INT_MAX;
    for(int i=0;i<dSize;i++)
    {
        if(isok(s, d[i]))
        {
            if(strlen(d[i])>max_len){
            j=i;
            max_len = strlen(d[i]);
            //printf("update j %d",j);
            }

        }
    }
    if(j!=INT_MAX)return d[j];
    return "";
}