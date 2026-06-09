```c
#define MAX_SIZE 500005
#define memset_s(a, b, c, d) memset(a, c, d)
#define memcpy_s(a, b, c, d) memcpy(a, c, b)
#define scanf_s(format, ...) scanf(format, __VA_ARGS__)
#define sprintf_s(a, b, format, ...) sprintf(a, format, __VA_ARGS__)

int MyStrAdd(char* strDest, unsigned int destMax, char ch, int num)
{
    if (strDest == NULL) {
        return 0;
    }
    int ret = sprintf_s(strDest, destMax, "%c%d", ch, num);
    if (ret == -1) {
        return 0;
    }
    return ret;
}

char* compressString(char* S){
    if (S == NULL) {
        return NULL;
    }
    if (*S == '\0') {
        return "\0";
    }
    char* SS = S;
    int len = 0;
    char* ret = (char*)malloc(sizeof(char) * MAX_SIZE);
    memset(ret, 0, sizeof(char) * MAX_SIZE);
    int index = 0;
    int cnt = 0;
    char preChar = *S;
    while (*S) {
        if (*S == preChar) {
            ++cnt;
        } else {
            index += MyStrAdd(ret + index, MAX_SIZE - index, preChar, cnt);
            cnt = 1;
            preChar = *S;
        }
        ++S;
        ++len;
    }
    index += MyStrAdd(ret + index, MAX_SIZE - index, preChar, cnt);
    if (index < len) {
        return ret;
    } else {
        return SS;
    }
}


```