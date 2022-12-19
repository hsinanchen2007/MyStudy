将填表动作取消，一次遍历过程中直接对最短回文子串进行拓展检查，记录过程中的最大子串，一遍遍历后既得最大回文子串
```
//根据当前回文字串向两边延伸，检查是否仍未回文
int from_subPalindrome(char *s, int *left, int *right)
{
    int iLength = strlen(s);
    while(*left >= 0 && *right < iLength )
    {
        if(s[*left] == s[*right])
        {
            (*left)--;
            (*right)++;
            continue;
        }
        break;
    }
    return *right - *left - 1;  //返回回文字串长度
}

char *longestPalindrome(char *s)
{
    int i = 0;
    int j = 0;
    int left = 0;    //左下标
    int right = 0;   //右下标
    int iLength = strlen(s);
    int max_left = iLength;  //最大回文子串起始位置
    int max_right = 0;       //最大回文子串结束位置
    int iMax = 0;    //最大回文字串长度
    int iTmp = 0;       //临时回文子串长度
    
    if(1 >= iLength)
        return s;
    if(2 == iLength)
    {
        if(s[0] == s[1])
        {
            return s;
        }
        else
        {
            char * ret = (char *)calloc(2, sizeof(char));
            ret[0] = s[0];
            ret[1] = '\0';
            return ret;
        }
        
    }
    

    
    //找到长度为2或者3的回文子串，并从找到的回文子串向外延伸检查是否依旧回文
    for(i = 0; i < iLength - 1; i++)
    {
        j = i + 1;
        if(s[i] == s[j])
        {
            left = i;
            right = j;
            iTmp = from_subPalindrome(s, &left, &right);
            if(iTmp > iMax)
            {
                iMax = iTmp;
                max_left = left + 1;
                max_right = right - 1;
                //printf(" LINE: %d %d LEFT:%d  RIGHT:%d\n", __LINE__, iTmp, max_left, max_right);
                //printf(" LINE: %d \n FROM_LEFT :%s \n FROM_RIGHT:%s \n", __LINE__, s + max_left, s + max_right);
                //continue;
            }
            //break;
        }
        if(s[i] == s[j + 1])
        {
            left = i;
            right = j + 1;
            iTmp = from_subPalindrome(s, &left, &right);
            //printf(" LINE: %d %d\n", __LINE__, iTmp);
            if(iTmp > iMax)
            {
                iMax = iTmp;
                max_left = left + 1;
                max_right = right - 1;
                //printf(" LINE: %d \n FROM_LEFT :%s \n FROM_RIGHT:%s \n", __LINE__, s + max_left, s + max_right);
            }
        }
    }
    char * retStr = (char *)calloc(iMax + 2, sizeof(char));
    for(i = 0; i < iMax; i++)
    {
        retStr[i] = s[max_left+i];
    }
    retStr[iMax + 1] = '\0';
    if(iMax == 0)
    {
        char * None_ = (char *)calloc(2, sizeof(char));
        None_[0] = s[0];
        None_[1] = '\0';
        return None_;
    }
        
    return retStr;
}
```
