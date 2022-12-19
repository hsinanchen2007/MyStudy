
![image.png](https://pic.leetcode-cn.com/51fc3373973f2475dd8649cdce207fb6e179eb2bf37b7995dd2400e4a2f4ba4e-image.png)




代码如下：
`typedef struct tagstrack {
    char *path;
    int pathLen;
    struct tagstrack *prev;
    struct tagstrack *next;
}STACK;

char * simplifyPath(char * path){
    int pathlen = strlen(path);
    int end = 0;
    int len = 0;
    int start = 0;
    int first = 1;
    STACK *head = NULL;
    STACK *tail = NULL;
    STACK *temp = NULL;

    if (pathlen <= 1) {
        return path;
    }

    while (start < pathlen) {
        end = start;
        while (end <= pathlen) {
            if (path[end++] == '/') {
                break;
            }
        }
        if (end > pathlen) {
            len = pathlen - start;
        } else {
            len = end - start;
        }
        if (strncmp((path + start), "/", len) == 0) {
            if (first) {
                STACK *curr = (STACK *)malloc(sizeof(STACK));
                char *p = (char *)malloc((len + 1) * sizeof(char));
                strncpy(p, (path + start), len);
                *(p + len) = '\0';
                curr->path = p;
                curr->prev = NULL;
                curr->next = NULL;
                curr->pathLen = len;
                head = curr;
                tail = curr;
                first = 0;
            }
        } else if (strncmp((path + start), "./", len) == 0) {
           
        } else if ((strncmp((path + start), "../", len) == 0) ||
                   (strncmp((path + start), "..", len) == 0)) {
            temp = tail->prev;
            if (temp != NULL) {
                free(tail->path);
                free(tail);
                temp->next = NULL;
                tail = temp;
            }
        } else {
            STACK *curr = (STACK *)malloc(sizeof(STACK));
            char *p = (char *)malloc((len + 1) * sizeof(char));
            strncpy(p, (path + start), len);
            *(p + len) = '\0';
            curr->path = p;
            curr->prev = tail;
            curr->next = NULL;
            curr->pathLen = len;

            tail->next = curr;
            tail = curr;
        }
        while (end <= pathlen) {
            if (path[end++] != '/') {
                break;
            }
        }
        if (end > pathlen) { // 调试1 ： 最后死循环，添加后解决
            break;
        }
        start = end - 1;
    }

    char *result = (char *)calloc(pathlen + 1, sizeof(char)); // 调试3 ：内存不足
    temp = head;
    while (temp != NULL) {
        if ((temp != head) && (temp == tail)) { // 调试2 ： 对用用例“/../”输出“”，应该是“/”
            if (temp->path[temp->pathLen - 1] == '/') {
                temp->path[temp->pathLen - 1] = '\0';
                temp->pathLen--;
            }
        }
        strncat(result, temp->path, temp->pathLen);
        temp = temp->next;
    }
    return result;
}`
