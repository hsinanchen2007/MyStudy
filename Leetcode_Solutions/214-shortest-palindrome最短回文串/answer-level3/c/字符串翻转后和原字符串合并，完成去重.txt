char * shortestPalindrome(char * s){
    int len = strlen(s);
    int i;
    char *tmpS, *retS;
    tmpS = (char*)malloc(len+1);
    memset(tmpS, 0 , len+1);
    for (i = 0; i < len; i++) {
        tmpS[len-i-1] = s[i];   //获取s字符串的翻转字符串
    }
    for (i = 0; i < len; i++) {
        if (0 == strncmp(tmpS+i, s, len-i)) {   //翻转后字符串后面部分和原字符串前面部分比较, 记录重合位置
            break;
        }
    }
    retS = (char*)malloc(2*len+1);
    memset(retS, 0 , 2*len+1);
    if (i == 0) {
        strncpy(retS, s, len);  //完全重合表示原先就是回文字符串
    } else {
        strncpy(retS, tmpS, i); //重合部分之前使用翻转字符串内容
        strncpy(retS+i, s, len); //其后部分使用原始字符串
    }

    free(tmpS);
    return retS;
}