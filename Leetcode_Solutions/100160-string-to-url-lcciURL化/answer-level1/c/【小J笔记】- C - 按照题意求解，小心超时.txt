- 使用sprintf一直超时，无语，老实使用strncpy
```
#define MAX_SIZE (1500010)
#define REPLACE_STRING_LEN (3)

char g_ret[MAX_SIZE];

char* replaceSpaces(char* S, int length)
{
    int i;
    int j;
    i = j = 0;        
    g_ret[0] = '\0';
    while (i < length) {
        if (S[i] != ' ') {
            g_ret[j] = S[i];            
            j++;            
        } else {     
            strncpy(g_ret + j, "%20", REPLACE_STRING_LEN * sizeof(char));       
            j += REPLACE_STRING_LEN;    
        }
        i++;
        g_ret[j] = '\0';        
    } 
    g_ret[j] = '\0';
    return g_ret;
}
```
