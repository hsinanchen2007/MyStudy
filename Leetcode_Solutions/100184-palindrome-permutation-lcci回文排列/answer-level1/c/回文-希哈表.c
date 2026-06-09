
//1、根据字母的范围构建希哈表，统计每个字符的个数。
//2、根据统计的字符个数，判断是否是回文。
bool canPermutePalindrome(char* s){
    int i,j;
    int length = strlen(s);
    int HEAPLIST[255]={0};
    for(i=0;i<length;++i)
    {
        HEAPLIST[s[i]]++;
    }
    i=0;
    for(j=0;j<255;++j)
    {
        if(HEAPLIST[j]%2==1)
        {
            ++i;
        }
    }
    if(i>1)
    {
        return false;
    }
    else
    {
        return true;
    }
}