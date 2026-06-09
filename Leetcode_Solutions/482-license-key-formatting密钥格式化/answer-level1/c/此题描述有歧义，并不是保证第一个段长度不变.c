此题描述有歧义，并不是保证第一个段长度不变，除此之外入参也别校验。我就是校验了长度，返回错误，不校验直接PASS了。
从尾巴开始遍历，可以保证第一段的长度




char * licenseKeyFormatting(char * S, int K){
    int i = 0;
    int charId = 0;
    int outId = 0;
    int len = strlen(S);
    char* out;
    
    out = (char*)malloc(2 * len * sizeof(char));
    memset(out, 0, 2 * len);
    
    charId = (len - 1);
    outId = 0;
    
    while (charId >= 0) {
        if (S[charId] != '-') {
            if ((S[charId] >= 'a') && (S[charId] <= 'z')) {
                S[charId] -= 32;
            }
            out[outId] = S[charId];
            outId++;
            if ((outId % (K + 1)) == K) {
                out[outId++] = '-';
            }
        }
        charId--;
    }
    
    if (outId == 0) {
        return "";
    }
    if (out[outId - 1] == '-') {
        outId--;
    }
    out[outId] = '\0';
    
    for (i = 0; i < (outId / 2); i++){
        char tmp = out[i];
        out[i] = out[outId - 1 - i];
        out[outId - 1 - i] = tmp;
    }    
    
    return out;
}
