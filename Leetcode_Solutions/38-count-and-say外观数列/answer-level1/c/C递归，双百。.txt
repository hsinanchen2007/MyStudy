char * countAndSay(int n){
    char* ret, *str;
    char temp;
    int i, count, index = 0;

    if(n == 1)
    {
        ret = (char* )malloc(1 * sizeof(char) + 1);

        ret[0] = '1';
        ret[1] = '\0';

        return ret;    
    }
    else
    {
        str = countAndSay(n-1);

        ret = (char* )malloc(2 * strlen(str) + 1);

        for(i = 0; str[i] != '\0'; i++)
        {
            if(i == 0)
            {
                temp = str[i];
                count = 1;
            }
            else
            {
                if(str[i] == temp)
                {
                    count++;
                }
                else
                {
                    ret[index++] = '0' + count;
                    ret[index++] = temp;

                    temp = str[i];
                    count = 1;
                }
            }
        }

        ret[index++] = '0' + count;
        ret[index++] = temp;
        ret[index] = '\0';

        free(str);

        return ret;
    }
}