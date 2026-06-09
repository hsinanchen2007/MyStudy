int lengthOfLongestSubstring(char * s){
    int max = 0;
    int len = strlen(s);
    char * sub  = malloc(len+1);
    memset(sub,0,len+1);
    char *subPrt = NULL;
    int  startChar = 0;
    for(int i = 0; i < len; i++){
        subPrt = strchr(sub, s[i]);
        if (subPrt == NULL) {
            sub[strlen(sub)] = s[i];
        }else {
            startChar += (subPrt - sub + 1);
            if (strlen(sub) > max) {
                max = strlen(sub);
            }
            memset(sub,0,len+1);
            strncpy(sub, (s + startChar), (i - startChar + 1));
        }
    }
    if (strlen(sub) > max) {
        max = strlen(sub);
    }
    free(sub);
    return max;
}