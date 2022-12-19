```C
#define MAX_SIZE 500005

#define ITOA_SIZE 10005
char itoaStr[ITOA_SIZE];

void ReverseItoaStr()
{
    char temp;
    char* p = itoaStr;
    char* q = itoaStr;
    while (*q) {
        ++q;
    }
    --q;

    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
}

void MyItoa(int num)
{
    bool isNegative = (num < 0);
    if (isNegative) {
        num = -num;
    }
    int i = 0;
    do {
        itoaStr[i++] = num % 10 + '0';
        num /= 10;
    } while(num);
    if (isNegative) {
        itoaStr[i++] = '-';
    }
    itoaStr[i] = '\0';
    ReverseItoaStr();
}

char* compressString(char* S){
    if (S == NULL) {
        return NULL;
    }
    if (*S == '\0') {
        return "\0";
    }
    char *SS = S;
    char* ret = (char*)malloc(sizeof(char) * MAX_SIZE);
    memset(ret, 0, sizeof(char) * MAX_SIZE);
    int index = 0;
    int cnt = 1;
    char preChar = *S;
    ret[index++] = preChar;
    ++S;
    while (*S) {
        if (*S == preChar) {
            ++cnt;
        } else {
            MyItoa(cnt);
            strcat(ret, itoaStr);
            cnt = 1;
            index += strlen(itoaStr);
            ret[index++] = *S;
            preChar = *S;
        }
        ++S;
    }
    MyItoa(cnt);
    strcat(ret, itoaStr);
    index += strlen(itoaStr);
    if (index < strlen(SS)) {
        return ret;
    } else {
        return SS;
    }
}

```