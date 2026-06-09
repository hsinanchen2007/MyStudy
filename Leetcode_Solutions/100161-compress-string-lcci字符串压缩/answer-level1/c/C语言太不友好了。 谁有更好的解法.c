```
char* compressString(char* S){
    char* chr = (char*)malloc(sizeof(char) * strlen(S) * 2);
    if (strlen(S) == 1) {
        return S;
    }
    int j = 1;
    int i = 0;
    int ch = 0;
    int count = 1;
    
    for (; i < strlen(S); i++) {
        if (S[j - 1] == S[j]) {
            count++;
        } else {
            chr[ch] = S[j - 1];
            if (count >= 10000) {
                chr[ch + 5] = count % 10 + '0';
                chr[ch + 4] = count % 100 / 10 + '0';
                chr[ch + 3] = count % 1000 / 100 + '0';
                chr[ch + 2] = count % 10000 / 1000 + '0';
                chr[ch + 1] = count / 10000 + '0';
                ch += 6; 
            }
            else if (count >= 1000 && count < 10000) {
                chr[ch + 4] = count % 10 + '0';
                chr[ch + 3] = count % 100 / 10 + '0';
                chr[ch + 2] = count % 1000 / 100 + '0';
                chr[ch + 1] = count / 1000 + '0';
                ch += 5; 
            }
            else if (count >= 100 && count < 1000) {
                chr[ch + 3] = count % 10 + '0';
                chr[ch + 2] = count % 100 / 10 + '0';
                chr[ch + 1] = count / 100 + '0';
                ch += 4; 
            }
            else if (count >= 10 && count < 100) {
                chr[ch + 1] = count / 10 + '0';
                chr[ch + 2] = count % 10 + '0';
                ch += 3;
            } else {
                chr[ch + 1] = count % 10 + '0';
                ch += 2;
            }
            count = 1;
        }
        j++;
    }
    chr[ch] = '\0';

    if (strlen(chr) >= strlen(S)) {
        return S;
    }
    return chr;
}
```
