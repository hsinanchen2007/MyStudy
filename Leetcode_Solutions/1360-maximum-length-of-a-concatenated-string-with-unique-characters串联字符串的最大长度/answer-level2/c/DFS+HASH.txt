bool IsSameChar(char* chLeft,char* chRight)
{
    int hashTmp[26] = {0};
    while((*chLeft) != '\0')
    {
        hashTmp[(*chLeft)-'a']++;
        if(hashTmp[(*chRight)-'a'] >0)
        {
            return true;
        }
        chLeft++;
    }

    while((*chRight) != '\0')
    {
        hashTmp[(*chRight)-'a']++;
        if(hashTmp[(*chRight)-'a']>1)
        {
            return true;
        }
        chRight++;
    }
    return false;
}

void dfsmaxLength(char ** arr,int arrSize,int* piRtn,char* pchTmp,int iStart)
{
    int iResult = strlen(pchTmp);
    if(iResult>(*piRtn))
    {
        printf("%s\r\n",pchTmp);
        (*piRtn) = iResult;
    }
    for(int i=iStart;i<arrSize;i++)
    {
        int OldLen = strlen(pchTmp);
        if(IsSameChar(pchTmp,arr[i]))
        {
            continue;
        }
        strcat(pchTmp,arr[i]);
        dfsmaxLength(arr,arrSize,piRtn,pchTmp,i+1);
        pchTmp[OldLen] = '\0';
    }
}

int maxLength(char ** arr, int arrSize)
{
    int iRtn = 0;
    char chTmp[1024] = {0};
    dfsmaxLength(arr,arrSize,&iRtn,chTmp,0);

    return iRtn;
}