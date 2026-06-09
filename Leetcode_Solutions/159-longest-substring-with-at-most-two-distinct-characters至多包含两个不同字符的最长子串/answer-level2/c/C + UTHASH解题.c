### 解题思路
使用UTHASH+滑动窗口

### 代码

```c
struct my_struct {
    char ch;
    int count;
    UT_hash_handle hh;
};

static struct my_struct* my_hash = NULL;

void addChar(char a)
{
    struct my_struct* tmp;
    HASH_FIND(hh, my_hash, &a, sizeof(char), tmp);
    if (tmp == NULL) {
        tmp = (struct my_struct*)malloc(sizeof(struct my_struct));
        tmp->ch = a;
        tmp->count = 1;
        HASH_ADD(hh, my_hash, ch, sizeof(char), tmp);
    }
    else {
        tmp->count++;
    }
}

void deleteChar(char a)
{
    struct my_struct* tmp;
    HASH_FIND(hh, my_hash, &a, sizeof(char), tmp);
    if (tmp == NULL) {
        return ;
    }
    else {
        tmp->count--;
        if (tmp->count <= 0) {
            HASH_DEL(my_hash, tmp);
            free(tmp);
        }
    }
}

int lengthOfLongestSubstringTwoDistinct(char * s){
    my_hash = NULL;
    int sLen = strlen(s);
    int start = 0;
    int end = start;
    int maxlen = 0;
    while (end < sLen) {
        if (HASH_COUNT(my_hash) <= 2) {
            addChar(s[end]);
            if (HASH_COUNT(my_hash) <= 2) {
                maxlen = fmax(maxlen, end - start + 1);
            }
            end++;
        }
        else {
            deleteChar(s[start]);
            start++;
        }
    }
    return maxlen;
}
```