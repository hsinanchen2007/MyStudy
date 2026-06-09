```
bool wordPattern(char * pattern, char * str){
    char **hash = (char **)malloc(26 * sizeof(char*));
    for (int i = 0; i < 26; ++i)
    {
        hash[i] = (char*)malloc(64 * sizeof(char));
        memset(hash[i], 0, 64 * sizeof(char));
    }
    int len = strlen(pattern);
    for (int i = 0; i < len; ++i)
    {
        char *p = str;
        while (p && *p != 0 && *p != ' ') ++p;
        if (' ' == *p) *p++ = 0;
        if (strlen(str) == 0)
            return false;
        int pos = pattern[i] - 'a';
        if (strlen(hash[pos]) == 0)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (j != pos && strlen(hash[j]) > 0)
                {
                    if (strcmp(hash[j], str) == 0)
                        return false;
                }
            }
            strcpy(hash[pos], str);
        }
        else
        {
            if (strcmp(hash[pos], str) != 0)
                return false;
        }
        str = p;        
    }
    if (strlen(str) > 0)
        return false;
    return true;
}
```
