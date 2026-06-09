bool isAnagram(char * s, char * t){
    int sArray[26] = {0};
    int tArray[26] = {0};

    int sNum = strlen(s); //字符串个数
    int tNum = strlen(t);
    int i;
    for( i = 0;i < sNum;i++)
    {
        sArray[ s[i] - 'a' ]++; //字符出现个数
    }
    for(int i = 0;i < tNum;i++)
    {
        tArray[ t[i] - 'a' ]++;
    }

    for(i = 0;i < 26; i++)
    {
        if(sArray[i] != tArray[i])
            return false;
    }
    return true;
}
