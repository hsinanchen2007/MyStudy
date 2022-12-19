c语言版，统计奇数个数的字符串个数即可。
```
#define ALPHABET_SIZE 26

bool canConstruct(char * s, int k){
    int hashmap[ALPHABET_SIZE] = {0};
    int length = strlen(s);

    if (k > length) {
        return false;
    }

    // generate hashmap.
    for (int i = 0; i < length; i++) {
        hashmap[s[i] - 'a']++;
    }

    // count.
    int res = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        res += hashmap[i] % 2 == 1;
    }

    return res <= k;
}
```
打周赛的时候，没有想到这么好的办法，有些可惜了。
