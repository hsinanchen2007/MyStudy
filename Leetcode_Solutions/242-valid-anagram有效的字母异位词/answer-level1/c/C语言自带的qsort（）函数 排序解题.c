bool isAnagram(char * s, char * t)
{
    int lens=strlen(s);
    int lent=strlen(t);
    if(lens!=lent)
    {
        return false;
    }
    int i;
    int compare(const void* a,const void* b)
    {
        char *pa=(char*)a;
        char *pb=(char*)b;
        return *pa-*pb;
    }
    
    qsort(s,lens,sizeof(char),compare);
    qsort(t,lent,sizeof(char),compare);
    
    for(i=0;i<lens;i++)
    {
        if(s[i]!=t[i])
        {
            return false;
        }
    }
    
    return true;
}

比起自己写排序会方便一些，嘻嘻