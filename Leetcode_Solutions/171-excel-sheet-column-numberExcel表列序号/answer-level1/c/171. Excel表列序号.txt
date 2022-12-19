人生中的第一个0ms，虽说题简单，依然很开心。

int titleToNumber(char * s){
    int ret;
    ret = *s-'A'+1; 
    while(*++s != '\0')
    {
        ret *= 26;
        ret += *s-'A'+1;
    }
    return ret;
}

