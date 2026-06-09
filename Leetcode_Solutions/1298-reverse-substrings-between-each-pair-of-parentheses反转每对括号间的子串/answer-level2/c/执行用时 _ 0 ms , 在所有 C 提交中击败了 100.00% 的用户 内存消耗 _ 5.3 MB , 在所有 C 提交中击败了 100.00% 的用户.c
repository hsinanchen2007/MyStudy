```
char * reverseParentheses(char * s){
    int len = strlen(s);
    if (len <= 0) {
        return NULL;
    }
    char * ret = (char *)malloc((len + 1) * sizeof(char));
    memset(ret, 0, (len + 1) * sizeof(char));
    char * tmp = (char *)malloc((len + 1) * sizeof(char));
    for (int i = 0, index = 0; i < len; i++, index++) {
        /*入队列*/
        ret[index] = s[i];
        //printf("ret[1]= %s \n", ret);
        if (s[i] == ')') {/*出队列*/
            int j = 0;
            memset(tmp, 0, (len + 1) * sizeof(char));
            while(index >= 0) {
                if (ret[index] == '(') {
                    ret[index] = '\0';
                    memcpy(ret + index, tmp, strlen(tmp));
                    //printf("ret[2]= %s \n", ret);
                    index = strlen(ret) - 1;
                    break;
                }
                if (ret[index] != ')') {
                    tmp[j++] = ret[index];
                }
                ret[index] = '\0';
                index--;
            }
        }
    }
    free(tmp);
    return ret;
}
```
