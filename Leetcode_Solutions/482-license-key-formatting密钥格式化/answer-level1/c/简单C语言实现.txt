char * licenseKeyFormatting(char * S, int K)
{
    int length = strlen(S);
    for (int t = 0;t<length;t++)
    {
       if (S[t] >= 'a' && S[t] <= 'z')
            S[t] -= 32;
    }
    int all = 0;
    char aaa[50000];
    for (int t = 0;t<length;t++)
    {
        if (S[t] != '-')
        {
            aaa[all++] = S[t];
        }
    }
    char * c = (char *)malloc(all*sizeof(char *)+333);
    int t = 0;
    int last = all%K;
    int allk = all/K;
    int num = 0;
    for (t;t<allk;t++)
    {
        for (int x = 0;x<K;x++)
        {
            c[t*(K+1)+x] = aaa[--all];
            num++;
        }
        if (all != 0)
        {
            c[t*(K+1)+K] = '-';
            num++;
        }
    }
    t = allk;
    for (int x = 0;x<last;x++)
    {
        c[t*(K+1)+x] = aaa[--all];
        num++;
    }
    char y;
    for (int t = 0;t<num/2;t++)
    {
        y = c[t];
        c[t] = c[num-t-1];
        c[num-t-1] = y;
    }
    c[num] = '\0';
    S = c;
    return S;
}