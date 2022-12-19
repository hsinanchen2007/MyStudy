int lengthOfLastWord(char * s){
    int index = -1, i, len;

    if(s == NULL)
    {
        return 0;
    }

    len = strlen(s);

    for(i = len - 1; i >= 0; i--)
    {
        if(s[i] != ' ')
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {
        for(i = index; i >= 0; i--)
        { 
            if(s[i] == ' ')
            {
                break;
            }
        }

        if(i == -1)
        {
            return index + 1;
        }
        else
        {
            return index - i;
        }
    }
    else
    {
        return 0;
    }
}