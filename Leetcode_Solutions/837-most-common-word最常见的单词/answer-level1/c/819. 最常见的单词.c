### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/45d876695e1f779bf66ba0eb14d51b7af32d86b93a3c1e5ccc1a0dcf82a9cc0f-image.png)

### 代码

```c
#define HASH_SIZE 1333
#define MAX_LETTER 10
#define DEBUG 0
int IsLetter(const char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return true;
    } else {
        return false;
    }
}
int GetCharValue(const char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return (int)(ch - 'a' + 1);
    } else if (ch >= 'A' && ch <= 'Z') {
        return (int)(ch - 'A' + 1);
    } else {
        return 0;
    }
}
int PrintHashTable(int *hashTable, int hashTableSize) {
    if (DEBUG != 1) return 0;

    for (int i = 0; i < hashTableSize; i++) {
        if (i != 0) {
            if (i % 10 == 0) {
                printf(",\n");
            } else {
                printf(", ");
            }
        }
        printf("%4d", hashTable[i]);
    }
    printf("\n");
    return 0;
}

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    if (paragraph == NULL || banned == NULL) {
        return NULL;
    }

    int *hashTable = (int *)malloc(sizeof(int) * (HASH_SIZE));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = 0;
    }

    // file the banned words
    char *p_char = NULL;
    long long sum = 0;
    int index = 0;
    for (int i = 0; i < bannedSize; i++) {
        p_char = banned[i];
        sum = 0;
        while (*p_char != '\0' && IsLetter(*p_char)) {
            sum <<= 5;
            sum += GetCharValue(*p_char);
            p_char++;
        }
        index = (int)(sum % HASH_SIZE);
        hashTable[index] = -1;
    }
    PrintHashTable(hashTable, HASH_SIZE);
    // file the hash table
    char *ret = (char *)malloc(50 + 1);
    char *p_ret = NULL;

    int maxTimes = 0;
    int i = 0;
    p_char = paragraph;

    while (*p_char != '\0') {
        sum = 0;
        while (IsLetter(*(p_char + i)) && i < MAX_LETTER) {
            sum <<= 5;
            sum += GetCharValue(*(p_char + i));
            i++;
        }
        index = (int)(sum % HASH_SIZE);
        if (hashTable[index] != -1 && sum != 0) {
            hashTable[index]++;
            if (hashTable[index] > maxTimes) {
                maxTimes = hashTable[index];
                p_ret = p_char;
            }
        }

        if (DEBUG) {
            printf("sum = %8lld, index = %5d, maxTimes = %4d, p_ret = %5d, i = %d\n",
                sum, index, maxTimes, (int)(p_char - paragraph), i);
        }


        if (i >= MAX_LETTER) {
            123;
            // search the first char that is not letter
            while (IsLetter(*(p_char + i))) {
                i++;
            }
        }

        p_char = p_char + i;
        i = 0;

        while (*p_char != '\0' && !IsLetter(*p_char)) {
            *p_char = '\0';
            p_char++;
        }
        //p_char++;
    }
    PrintHashTable(hashTable, HASH_SIZE);

    p_char = p_ret;

    for (int j = 0; j<50; j++) {
        if (*p_char != '\0') {
            ret[j] = GetCharValue(*p_char) + 'a' - 1;
        } else {
            ret[j] = '\0';
            break;
        }

        p_char++;
    }

    // return result
    return ret;
}

/* test case
"Bob hit a ball, the hit BALL flew far after it was hit."
["hit"]

"Bob hit a ball, the hit BALL flew far after it was hit."
["hit","ball"]
*/
```