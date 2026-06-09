int countSegments(char * s){
    int i;
    int len = strlen(s);
    int counter = 0;
    for(i = 0; i < len; i++)
    {
        if (i != 0)
        {
            if (s[i - 1] == ' ' && s[i] != ' ')
            {
            counter ++;
            }  
        }
        else 
        {
            if(s[i] != ' ')
            {
                counter ++;
            }
        }
    }
    return counter;
}