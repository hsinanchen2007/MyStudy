![B7A2E8F5-6240-42FB-9298-9F0D1EE32295.jpeg](https://pic.leetcode-cn.com/f04d6c999db87901a7948dce702bd0b677f7c839c7f9da1a8bbfd10a5cdf6d1a-B7A2E8F5-6240-42FB-9298-9F0D1EE32295.jpeg)

```
typedef struct {
    char c;
    struct ListNode *next;
} ListNode;


ListNode *g_this = NULL;
int g_thisSize = 0;

void ListNodePush(char c) {
    ListNode *tmpListNode = g_this;
    printf("push: c:%c\n", c);
    if ((g_this == NULL) || (g_thisSize == 0)) {
        g_this = (ListNode *)malloc(sizeof(ListNode));
        g_this->c = c;
        g_this->next = NULL;
        g_thisSize = 1;
    } else {
        while(g_this->next != NULL) {
            g_this = g_this->next;
        }
        g_this->next = (ListNode *)malloc(sizeof(ListNode));
        g_this = g_this->next;
        g_this->c = c;
        g_this->next = NULL;
        g_this = tmpListNode;
        g_thisSize++;
    }
}

bool ListNodePop(char *c) {
    ListNode *tmpListNode = g_this;
    ListNode *tmpAgoListNode = g_this;
    printf("push: begin: g_thisSize: %d\n", g_thisSize);
    if (g_thisSize == 0) {
        return false;
    }
    if (tmpListNode == NULL) {
        g_thisSize = 0;
        return false;
    }
    if (tmpListNode->next == NULL) {
        *c = tmpListNode->c;
        free(tmpListNode);
        g_this = NULL;
        g_thisSize = 0;
        printf("pop: c:%c\n", *c);
        return true;
    }
    while(tmpListNode->next != NULL) {
        tmpAgoListNode = tmpListNode;
        tmpListNode = tmpListNode->next;
    }
    *c = tmpListNode->c;
    free(tmpListNode);
    tmpListNode = NULL;
    g_thisSize--;
    tmpAgoListNode->next = NULL;
    printf("pop: c:%c\n", *c);
    return true;
}

bool isValid(char * s)
{
    int sLen = strlen(s);
    int i;
    char c;
    bool isTrue;
    g_thisSize = 0;
    for (i = 0; i < sLen; i++) {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
            ListNodePush(s[i]);
            printf("if: g_thisSize: %d\n", g_thisSize);
        } else {
            isTrue = ListNodePop(&c);
            if (isTrue == false) {
                return false;
            }
            if ((s[i] == ')') && (c != '(')) {
                return false;
            } else if ((s[i] == ']') && (c != '[')) {
                return false;
            } else if ((s[i] == '}') && (c != '{')) {
                return false;
            }
            printf("else: g_thisSize: %d\n", g_thisSize);
        }
    }
    if (g_thisSize != 0) {
        while(ListNodePop(&c)) {
            ;
        }
        free(g_this);
        g_thisSize = 0;
        return false;
    }
    return true;
}
```
