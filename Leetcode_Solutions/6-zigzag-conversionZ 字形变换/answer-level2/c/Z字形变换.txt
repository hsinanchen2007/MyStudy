char * convert(char * s, int numRows) {
    if (s == NULL || numRows <= 1) {          /// 只输出一行时，无需转换
        return s;
    }
    int len = strlen(s);
    if (len == 0) {
        return s;
    }
    char *ret = (char*)malloc(len + 1);
    int gap; 
    int j;    
    int ret_inx = 0;
    for (int i = 0; i < numRows; i++) {
        j = i;
        gap = (numRows - 1) * 2 - 2 * i;
        if (gap == 0) {
            gap = 2 * i;
        }
        ret[ret_inx++] = s[j];
        if (ret_inx >= len) {
            break;
        }
        while (j + gap < len) {
            j = j + gap;
            ret[ret_inx++] = s[j];
            if (i > 0 && i < numRows - 1) {
                gap = (numRows - 1) * 2 - gap;  ///行号为i, 则字母之间的间隔,要么是2i,要么是（numRows - 1） *2 - 2i
            }
        }
    }
    ret[ret_inx++] = '\0';
    return ret;
}