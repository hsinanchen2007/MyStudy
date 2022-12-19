```c
#define SIZE 105

void ToLower(char* s)
{
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += ('a' - 'A');
        }
        ++s;
    }
}

bool IsContain(char* s, char ch)
{
    while (*s) {
        if (*s == ch) {
            return true;
        }
        ++s;
    }
    return false;
}

int CountNum(char* s)
{
    int count = 0;
    while (*s) {
        if (*s >= '0' && *s <= '9') {
            ++count;
        }
        ++s;
    }

    return count;
}

char * maskPII(char * S){
    int i;
    char* ret = (char*)malloc(sizeof(char) * SIZE);
    if (IsContain(S, '@')) {
        ToLower(S);
        char* suffix = strstr(S, "@");
        ret[0] = S[0];
        strcpy(ret + 1, "*****");
        ret[6] = *(suffix - 1);
        strcpy(ret + 7, suffix);
    } else {
        int numCount = CountNum(S);
        int len = strlen(S);
        int index;
        int count = 4;
        int i;

        switch (numCount) {
            case 10:
                strcpy(ret, "***-***-");
                index = 11;
                break;
            case 11:
                strcpy(ret, "+*-***-***-");
                index = 14;
                break;
            case 12:
                strcpy(ret, "+**-***-***-");
                index = 15;
                break;
            case 13:
                strcpy(ret, "+***-***-***-");
                index = 16;
                break;
            default:
                break;
        }
        ret[index + 1] = '\0';
        for (i = len - 1; i >= 0 && count; --i) {
            if (S[i] >= '0' && S[i] <= '9') {
                ret[index--] = S[i];
                --count;
            }
        }
    }
    return ret;
}

```