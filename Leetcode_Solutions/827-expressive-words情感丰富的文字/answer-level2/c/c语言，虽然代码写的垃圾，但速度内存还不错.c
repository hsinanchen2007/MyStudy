执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了76.84%的用户


char get_str(char *S, int *count)
{
    char *s = S;
    char str = S[0];
    int cnt = 0;
    while (*s == str) {
        cnt++;
        s++;
    }
    *count = cnt;
    return str;
}

bool isStr(char *str, char *words_tmp)
{
    char s1;
    char s2;
    int str_cnt;
    int words_cnt;

    while (*str != '\0' && *words_tmp != '\0') {
        s1 = get_str(str, &str_cnt);
        s2 = get_str(words_tmp, &words_cnt);
        
        str += str_cnt;
        words_tmp += words_cnt;

        if (s1 != s2 || str_cnt < words_cnt || ((str_cnt < 3) && (str_cnt != words_cnt))) {
            return false;
        }
    }
    if (*str == *words_tmp) {
        return true;
    }
    return false;
}

int expressiveWords(char * S, char ** words, int wordsSize){
    int cnt = 0;
    char *words_tmp;

    for (int i = 0; i < wordsSize; i++) {
        words_tmp = words[i];
        if (isStr(S, words_tmp)) {
            cnt++;
        }
    }
    return cnt;
}