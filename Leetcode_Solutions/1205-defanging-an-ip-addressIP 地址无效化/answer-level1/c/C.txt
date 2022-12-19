

char * defangIPaddr(char * address)
{
    static char result[100];
    int i;
    int j=0;
    for (i=0;address[i] != '\0';i++)
    {
        if (address[i] == '.')
        {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        }
        else
        {
            result[j++] = address[i];
        }
    }
    result [j] = '\0';
    return result;
}