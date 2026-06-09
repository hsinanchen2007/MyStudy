#define max 10000000
char * reverseWords(char * sss)
{
        if (s == NULL) {
                return NULL;
        }
        char *ret = (char*)malloc(max * sizeof(char));
        memset(ret, 0, sizeof(ret));
        int pos = max - 1;
        char *ret_head = ret;

        char *str = strtok(s, " ");
        ret[pos--] = '\0';
        while (str != NULL) {
                int len = strlen(str);
                pos -= len;
                memcpy(&ret[pos], str, len * sizeof(char));
                pos--;
                ret[pos] = ' ';
                str = strtok(NULL, " ");
        }

        pos++;
        return &ret[pos];
}
