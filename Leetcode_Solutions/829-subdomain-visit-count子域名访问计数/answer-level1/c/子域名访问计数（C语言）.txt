### 解题思路
哈希表存储每个域名出现的次数，哈希表无需存储每个域名内容

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_ROOM 26
char **dict = NULL;
struct node {
    int index;
    int offset;
    int len;
    int cnt;
    struct node *next;
};

struct hash {
    struct node* domainList[HASH_ROOM];
} g_hashTab;

void HashInit()
{
    memset(&g_hashTab, 0, sizeof(g_hashTab));
}

void HashDelete()
{
    struct node *cur = NULL;
    struct node *tmp = NULL;
    int i;

    for (i = 0; i < HASH_ROOM; i++) {
        cur = g_hashTab.domainList[i];
        while (cur != NULL) {
            tmp = cur->next;
            free(cur);
            cur = tmp;
        }
    }
}

int FindSubDomain(char *domain)
{
    int len = strlen(domain);
    int tag = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (tag == 0 && domain[i] == '.') {
            tag = 1;
        }

        if (tag == 1 && domain[i] != '.') {
            return i;
        }
    }
    return i;
}

void HashInsert(int offset, int index, int cnt)
{
    struct node *cur = NULL;
    int idx;
    int len;
    char *p = NULL;
    p = &dict[index][offset];

    len = strlen(p);
    idx = p[0] % HASH_ROOM;
    cur = g_hashTab.domainList[idx];

    while (cur != NULL) {
        if (len == cur->len &&
            memcmp(p, &dict[cur->index][cur->offset], len) == 0) {
                cur->cnt += cnt;
                return;
            }
        cur = cur->next;
    }

    cur = (struct node *)malloc(sizeof(struct node));
    cur->index = index;
    cur->offset = offset;
    cur->len = len;
    cur->cnt = cnt;
    cur->next = g_hashTab.domainList[idx];
    g_hashTab.domainList[idx] = cur;
}

void SaveIntoHash(char *domain, int index)
{
    int len = strlen(domain);
    int i;
    int cnt = 0;
    for (i = 0; i < len; i++) {
        if (domain[i] > '9' || domain[i] < '0') {
            break;
        }
        cnt = cnt * 10 + domain[i] - '0';
    }
    i++; // blank space
    do {
        HashInsert(i, index, cnt);
        i += FindSubDomain(domain + i);
    } while (i < len);
}

int HashCount()
{
    struct node *cur = NULL;
    int cnt = 0;
    int i;
    for (i = 0; i < HASH_ROOM; i++) {
        cur = g_hashTab.domainList[i];
        while (cur != NULL) {
            cnt++;
            cur = cur->next;
        }
    }
    return cnt;
}

char **subdomain(int *size)
{
    struct node *cur = NULL;
    char **result = NULL;
    char *p = NULL;
    int num;
    int cnt = 0;
    int offset;
    int i;

    num = HashCount();
    if (num <= 0) {
        return NULL;
    }
    result = (char **)malloc(sizeof(char *) * num);
    for (i = 0; i < HASH_ROOM; i++) {
        cur = g_hashTab.domainList[i];
        while (cur != NULL) {
            p = (char *)malloc(cur->len + 1 + 7);
            offset= sprintf(p, "%d", cur->cnt);
            p[offset++] = ' ';
            memcpy(p + offset, &dict[cur->index][cur->offset], cur->len);
            offset += cur->len;
            p[offset] = 0;
            result[cnt++] = p;
            cur = cur->next;
        }
    }
    *size = cnt;
    return result;
}

char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize){
    int i;
    char **result = NULL;
    int sz = 0;

    if (cpdomains == NULL || cpdomainsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    dict = cpdomains;

    HashInit();

    for (i = 0; i < cpdomainsSize; i++) {
        SaveIntoHash(cpdomains[i], i);
    }

    result = subdomain(&sz);

    *returnSize = sz;

    HashDelete();

    return result;
}
```