

char * longestCommonPrefix(char ** strs, int strsSize)
{
    int i,j;
    int flag = 1;
    
    if(strsSize == 0)
    {
        char * ret = (char *)malloc(sizeof(char)*1);
        ret[0] = '\0';
        return ret;
    }
    
    j = 0;
    while (1 == flag)
    {
        for (i = 0; i < strsSize; i++)
        {
            if ((strs[i][j] == '\0') || (strs[0][j] != strs[i][j]))
            {
                flag = 0;
                break;
            }
        }
        if(i == (strsSize))
        {
            j++;       
        }
        
    }
    strs[0][j] = '\0';
    return strs[0];
}