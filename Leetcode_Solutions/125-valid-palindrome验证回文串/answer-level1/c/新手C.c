bool isPalindrome(char * s)
{
    if(s == NULL)
        return true;

    int len = strlen(s);
    char* news=(char*)malloc(sizeof(char)*len);
    int count = 0;

    for(int i = 0;i < len;i++)
    {
        if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            news[count] = s[i];
            count++;
        }    
    }

    for(int n = 0;n < count;n++)
    {
        if(news[n] >= 'A' && news[n] <= 'Z')
            news[n] = news[n] + 32;
    }

    int first = 0,last = count-1;
    
    while(first < last)
    {
        if(news[first] == news[last])
        {
            first++;
            last--;
        }
        else
            return false;
    }

    return true;    
}
