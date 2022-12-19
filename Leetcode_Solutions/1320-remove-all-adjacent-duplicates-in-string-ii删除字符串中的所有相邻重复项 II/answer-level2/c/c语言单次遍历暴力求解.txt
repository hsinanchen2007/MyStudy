int getStackCharCnt(char *s, int pos)
{
    int cnt = 1;
    if( pos == 0) return  0;
    for (int i = pos - 1; i > 0; --i) {
        if(s[i] == s[i-1]){
            cnt++;
        } else {
            break;
        }
    }
    return cnt;
}

char * removeDuplicates(char * s, int k){
    int len = strlen(s);
    int pos = 0;
    int tCnt = 0;
    char *ret = malloc(sizeof(char) * (len + 1));

    for(int i = 0; i < len; ++i)  {
        ret[pos++] = s[i];
        if(pos == 1){
            tCnt = 1;
            continue;
        }
        if(s[i] == ret[pos - 2]) {
            tCnt++;
        } else {
            tCnt = 1;
        }
        if(tCnt == k) {
            pos -= k;
            tCnt = getStackCharCnt(ret, pos);
        }
    }
    ret[pos] = 0;
    return ret;
}