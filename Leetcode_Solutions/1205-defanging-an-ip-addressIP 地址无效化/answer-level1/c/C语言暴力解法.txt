    char * defangIPaddr(char * address){
        char *rec =malloc(23 * sizeof(char));
        int j = 0;
        for(int i = 0; address[i] != '\0'; i++)
        {
            if (address[i] != '.')
                rec[j++] = address[i];
            else
            {
                rec[j++] = '[';
                rec[j++] = '.';
                rec[j++] = ']';
            }
        
        }
        rec[j]= '\0';
        return rec;
    }

