最小回文子串长度可能是2也可能是3,因此找到长度为2或者3的字串向两边同时延伸，即可找出最大回文串
继超时之后，根据填表（二维数组）找到回文子串的拓展关系（所有回文串都由回文字串构成）。检查每一个最小回文字串的可延伸长度，记录最大长度和对应的下标即可得到最大回文子串。
内存占用过大，时间复杂度由超时的O(n^3)降到O(n^2),还有优化空间。
# *要注意字符串的结束符号*
```
#define max(a, b)  (a > b ? a : b)

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

    char **table = (char **)calloc(iLength, sizeof(char *));
    for(i = 0; i < iLength; i++)
    {
        table[i] = (char *)calloc(iLength, sizeof(char));
    }
    
    //填表，对角线的位置一定(纵横坐对应的字符)相等
    for(i = 0; i < iLength; i++)
    {
        table[i][i] = s[i];
    }
    
    //找到长度为2或者3的回文子串，并从找到的回文子串向外延伸检查是否依旧回文
    for(i = 0; i < iLength - 1; i++)
    {
        j = i + 1;
        if(table[i][i] == s[j])
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
        if(table[i][i] == s[j + 1])
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


