两重hash，第二遍用了三个hash表，不得不说，在hash方面，C语言就是垃圾。
字符串转数字hash函数参考网上，数字再hash自己写的。
基本思路：
1、把原始单词列表，大写转小写后的列表，和把元音替换掉的列表，分别做hash（两重）。
1、待查单词，用hash先原单词寻找，再转小写寻找，再把元音也换掉查找。哪个能找到就返回处理下个词。
```
#define MAX_SIZE 5001
#define HASH_LEN 1000
struct HashData {
    int key;
    int val;
};
struct HashData g_hash[HASH_LEN][HASH_LEN] = {0};
struct HashData g_hash1[HASH_LEN][HASH_LEN] = {0};
struct HashData g_hash2[HASH_LEN][HASH_LEN] = {0};
int GetKey(int num) {
    return abs(num) % HASH_LEN;
}
int GetHash(int num) {
    int key = GetKey(num);
    for (int i = 0; i < HASH_LEN; i++) {
        if (g_hash[key][i].key == num) {
            return g_hash[key][i].val;
        }
        if (g_hash[key][i].key == -1) {
            break;
        }
    }
    return -1;
}
int AddHash(int num, int val) {
    int key = GetKey(num);
    for (int i = 0; i < HASH_LEN; i++) {
        if (g_hash[key][i].key == num) {
            g_hash[key][i].val = val;
            break;
        }
        if (g_hash[key][i].key == -1) {
            g_hash[key][i].key = num;
            g_hash[key][i].val = val;
            break;
        }
    }
    return 0;
}
int GetHash2(int num) {
    int key = GetKey(num);
    for (int i = 0; i < HASH_LEN; i++) {
        if (g_hash2[key][i].key == num) {
            return g_hash2[key][i].val;
        }
        if (g_hash2[key][i].key == -1) {
            break;
        }
    }
    return -1;
}
int AddHash2(int num, int val) {
    int key = GetKey(num);
    for (int i = 0; i < HASH_LEN; i++) {
        if (g_hash2[key][i].key == num) {
            g_hash2[key][i].val = val;
            break;
        }
        if (g_hash2[key][i].key == -1) {
            g_hash2[key][i].key = num;
            g_hash2[key][i].val = val;
            break;
        }
    }
    return 0;
}

int GetHash1(int num) {
    int key = GetKey(num);
    for (int i = 0; i < HASH_LEN; i++) {
        if (g_hash1[key][i].key == num) {
            return g_hash1[key][i].val;
        }
        if (g_hash1[key][i].key == -1) {
            break;
        }
    }
    return -1;
}
int AddHash1(int num, int val) {
    int key = GetKey(num);
    for (int i = 0; i < HASH_LEN; i++) {
        if (g_hash1[key][i].key == num) {
            g_hash1[key][i].val = val;
            break;
        }
        if (g_hash1[key][i].key == -1) {
            g_hash1[key][i].key = num;
            g_hash1[key][i].val = val;
            break;
        }
    }
    return 0;
}
void ChangeWord(char *str, int len) {
    for (int j = 0; j < len; j++) {
        if (isupper(str[j])) {
            str[j] = tolower(str[j]);
        }
    }
    return;
}
void ChangeWord1(char *str, int len) {
    for (int j = 0; j < len; j++) {
        if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u') {
            str[j] = 'a';
        }
    }
    return;
}
long long GetH(char *str, int len) {
    int seed = 313;  
    long long hash = 0;
    for(int i = 0; i < len; str++, i++)   
    {   
      hash = (hash * seed) + (*str);   
    }   
    return hash;   
}   
void HashInit() {
    for (int i = 0; i < HASH_LEN; i++) {
        for (int j = 0; j < HASH_LEN; j++) {
            g_hash[i][j].key = -1;
            g_hash[i][j].val = -1;
        }
    }
    for (int i = 0; i < HASH_LEN; i++) {
        for (int j = 0; j < HASH_LEN; j++) {
            g_hash1[i][j].key = -1;
            g_hash1[i][j].val = -1;
        }
    }
    for (int i = 0; i < HASH_LEN; i++) {
        for (int j = 0; j < HASH_LEN; j++) {
            g_hash2[i][j].key = -1;
            g_hash2[i][j].val = -1;
        }
    }
}
char ** spellchecker(char ** wordlist, int wordlistSize, char ** queries, int queriesSize, int* returnSize){
    char **copy = (char**)malloc(wordlistSize * sizeof(char*));
    char **copy1 = (char**)malloc(wordlistSize * sizeof(char*));
    HashInit();
    for (int i = wordlistSize - 1; i >= 0; i--) {
        copy[i] = (char**)malloc((strlen(wordlist[i]) + 1) * sizeof(char));
        memset(copy[i], 0, (strlen(wordlist[i]) + 1) * sizeof(char));
        strncpy(copy[i], wordlist[i], strlen(wordlist[i]));   
        AddHash2(GetH(copy[i], strlen(copy[i])), i);  
        ChangeWord(copy[i], strlen(copy[i]));
        AddHash(GetH(copy[i], strlen(copy[i])), i);  
        
        copy1[i] = (char**)malloc((strlen(wordlist[i]) + 1) * sizeof(char));
        memset(copy1[i], 0, (strlen(wordlist[i]) + 1) * sizeof(char));
        strncpy(copy1[i], copy[i], strlen(wordlist[i]));
        ChangeWord1(copy1[i], strlen(copy1[i]));
        AddHash1(GetH(copy1[i], strlen(copy1[i])), i);
    }
    char **result = (char**)malloc(MAX_SIZE * sizeof(char*));
    memset(result, 0, MAX_SIZE * sizeof(char*));
    for (int i = 0; i < queriesSize; i++) {
        int h = GetHash2(GetH(queries[i], strlen(queries[i])));
        if (h != -1) {
            result[i] = wordlist[h];
            continue;
        }
        ChangeWord(queries[i], strlen(queries[i]));
        h = GetHash(GetH(queries[i], strlen(queries[i])));
        if (h != -1) {
            result[i] = wordlist[h];
            continue;
        }
        ChangeWord1(queries[i], strlen(queries[i]));
        h = GetHash1(GetH(queries[i], strlen(queries[i])));
        if (h != -1) {
            result[i] = wordlist[h];
            continue;
        }
        result[i] = "";
    }
    *returnSize = queriesSize;
    return result;
}
```


