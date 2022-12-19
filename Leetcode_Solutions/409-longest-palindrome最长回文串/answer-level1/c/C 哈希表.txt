
 每个字符的个数如果是偶数，取其值n，如果是奇数个，取n-1;
 最后判断组成的回文长度小于原字符串长度，总长度+1.

int longestPalindrome(char * s){

    if(s == NULL)
    {
        return 0;
    }

    int i = 0;
    int len = strlen(s);
    int Nums = 0;
    int sHash[128] = {0};

    for(i=0;i<len;i++)
    {
       sHash[s[i]]++;
    }

    for(i=0;i<128;i++)
    {
        if(sHash[i] > 1)
        {
            Nums += ((sHash[i]%2) == 0)?sHash[i]:(sHash[i]-1);
        } 
    }

    return (len > Nums)?(Nums+1):Nums;
}