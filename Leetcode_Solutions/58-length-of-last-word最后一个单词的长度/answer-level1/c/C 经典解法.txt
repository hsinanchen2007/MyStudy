
int lengthOfLastWord(char * s){
    int slen = strlen(s);
    int num = 0;
    bool flag = false; // 字符尾第一个字符的‘ ’的标记位
    for (int i = slen - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            num++;
            flag = true;
        }
        else {
            if (flag == false) {
                continue;
            } else {
                break;
            }
        }
    }
    return num;
}
