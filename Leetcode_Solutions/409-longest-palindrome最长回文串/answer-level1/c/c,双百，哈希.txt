int longestPalindrome(char * s){
    int len,i;
    int t;
    int re = 0;
    len = strlen(s);
    if(len<2)
        return len;
    int hash[52] = {0};//26*2 = 52个字母
    i = 0;
    while(i<len)
    {
        if(s[i] <= 'Z')
        {//大写字母在前26
            t = s[i]-'A';
            hash[t]++;
        }
        else
        {//为小写字母,在后26个
            t = s[i]-'a'+26;
            hash[t]++;
        }
        i++;
    }
    for(i = 0;i < 52;i++)
    {
        if(hash[i]%2 == 0)//偶数个
            re +=hash[i];
        else
            re += hash[i]-1;
    }
    if(re<len)//说明有未加入的，可以随意加一个，加到正中间
        return re+1;
    else//说明全部都加入了
        return re;
}