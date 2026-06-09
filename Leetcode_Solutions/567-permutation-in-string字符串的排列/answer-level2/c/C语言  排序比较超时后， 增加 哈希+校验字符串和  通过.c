```C []
int compareSelect(const void *a, const void *b) {
     char tmpA = *(char*)a;
     char tmpB = *(char*)b;

     if (tmpA > tmpB) {
         return 1;
     } else {
         return -1;
     }
}

int GetStrSum(char *s, int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += s[i];
    }
    return sum;
}

bool checkInclusion(char * s1, char * s2) {
    if ((s1 == NULL) || (s2 == NULL)) {
        return false;
    }

    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int newStrLen = s1Len + 4;
    char *tmpStr = (char*)malloc(newStrLen);
    int loop = s2Len - s1Len + 1;

    int hashFlag[0x200] = {0};
    for (int j = 0; j < s1Len; ++j) {
        hashFlag[s1[j]]++;
    }

    int s1Sum = GetStrSum(s1, s1Len);
    qsort(s1, strlen(s1), sizeof(char), compareSelect);

    bool result = false;

    for (int i = 0; i <= loop; ++i) {
        if (hashFlag[s2[i]] == 0) {
            continue;
        }
        int sum = GetStrSum(&s2[i], s1Len);
        if (sum != s1Sum) {
            continue;
        }

        memset(tmpStr, 0, s1Len + 1);
        memcpy(tmpStr, s2 + i, s1Len);
        qsort(tmpStr, s1Len, sizeof(char), compareSelect);
        if (memcmp(s1, tmpStr, s1Len) == 0) {
            result = true;
            break;
        }
    }
    
    free(tmpStr);
    return result;
}
```