char * toLowerCase(char * str) {
    char * res = malloc(sizeof(char) * (strlen(str) + 1));
    char * res_copy = res;
    char * cs = str;
    while (*cs) {
        char w = *cs;
        if (w >= 'A' && w <= 'Z') {
            w = w + 32;
        }
        
        *res_copy++ = w;
        cs ++;
    }
    
    *res_copy = '\0';
    return res;
}
