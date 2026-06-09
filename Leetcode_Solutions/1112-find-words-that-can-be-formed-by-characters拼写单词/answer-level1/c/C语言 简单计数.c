```c
#define SIZE 26
int g_map[SIZE];
int copy_map[SIZE];

int countCharacters(char ** words, int wordsSize, char * chars){
    if (words == NULL || wordsSize == 0 || chars == NULL) {
        return 0;
    }
    memset(g_map, 0, sizeof(g_map));
    while (*chars) {
        ++g_map[*chars - 'a'];
        ++chars;
    }
    int ret = 0;
    int len;
    int i;
    for (i = 0; i < wordsSize; ++i) {
        len = 0;
        memcpy(copy_map, g_map, sizeof(g_map));
        while (*words[i]) {
            if (!copy_map[*words[i] - 'a']) {
                break;
            }
            --copy_map[*words[i] - 'a'];
            ++words[i];
            ++len;
        }
        if (!*words[i]) {
            ret += len;
        }
    }
    return ret;
}

```