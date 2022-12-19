int strStr(char * haystack, char * needle){

    int h_len = strlen(haystack);
    int n_len = strlen(needle);
    if (haystack == NULL || needle == NULL || n_len == 0) {
        return 0;
    }
        
    for(int i = 0; i < h_len; i++)
    {
        int tmp = i;
        int j = 0;
        while(haystack[tmp++] == needle[j++]){
            if (j == n_len && tmp <= h_len) {
                return i;
            }
        }
    }
    return -1;
}