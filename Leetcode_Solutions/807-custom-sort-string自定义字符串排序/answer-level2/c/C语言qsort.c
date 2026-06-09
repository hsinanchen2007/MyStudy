```
int priority[26] = {0};

int compare(const void* ch1, const void* ch2) {
    int index1 = *(char*)ch1 - 'a';
    int index2 = *(char*)ch2 - 'a';
    return priority[index1] > priority[index2];
}

char * customSortString(char * S, char * T){
    for (int i = 0; i < strlen(S); i++) {
        int index = S[i] - 'a';
        priority[index] = i;
    }
    qsort(T, strlen(T), sizeof(char), compare);
    return T;
}
```
