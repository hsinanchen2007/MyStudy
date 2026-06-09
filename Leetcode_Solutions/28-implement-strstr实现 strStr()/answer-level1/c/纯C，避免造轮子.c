int strStr(char * haystack, char * needle)
{
    if (needle == NULL) {
        return 0;
    }
    
    char *ret = strstr(haystack, needle);
    if (ret) {
        return (int)ret - (int)haystack;
    } else {
        return -1;
    }
    
    return ;
}