思路：
    思路比较简单，当遇到一个.时，表示当前目录，则跳过，继续处理；当遇到两个.时，表示返回父目录，对应栈弹出操作；其他情形当成是普通的目录，进行入栈操作。
    需要注意的一点是：对于点号，只有"."和".."这两个组合才有特殊含义，分别表示当前目录和父目录，其他场景中“.”是作为普通字符的，例如 “/...”、“/.hello”或“/..world”等。

代码：
typedef struct dir {
    int index;
    int len;
} dir_t;

#define MAXSIZE     100

char * simplifyPath(char * path){
    dir_t *dirStack = NULL;
    int top = -1;   /* 栈顶指针 */
    int len;
    int i, j;
    char *res = NULL;

    len = strlen(path);
    if (len == 0) {
        return NULL;
    }

    /* 申请栈空间 */
    dirStack = (dir_t *)malloc(sizeof(dir_t) * MAXSIZE);
    if (dirStack == NULL) {
        return NULL;
    }
    memset(dirStack, 0, sizeof(dir_t) * MAXSIZE);
    
    i = 0;
    while (i < len) {
        if (path[i] == '/') {
            while (i < len && path[i] == '/') { /* 处理冗余的/ */
                i++;
            }
        } else {
            j = i;  /* 保存当前位置 */
            while (i < len && path[i] != '/') { /* 找到下一个分隔符/的位置 */
                i++;
            }
            if (i - j == 1 && path[j] == '.') { /* 当前目录 */
                continue;
            } else if (i - j == 2 && path[j] == '.' && path[j+1] == '.') {  /* 返回父目录 */
                if (top >= 0) {
                    top--;
                }
            } else {    /* 加入新目录 */
                top++;
                dirStack[top].index = j;
                dirStack[top].len = i - j;
            }
        }
    }

    res = (char *)malloc(len + 1);
    memset(res, 0, len + 1);

    res[0] = '/';
    if (top < 0) {
        return res;
    }

    /* 根据栈中保存的目录名称构造输出路径字符串 */
    for (i = 1, j = 0; j <= top; j++) {
        strncpy(res + i, path + dirStack[j].index, dirStack[j].len);
        i += dirStack[j].len;
        res[i] = '/';
        i++;
    }

    /* 清除输出字符串中最后一个‘/’ */
    res[i-1] = '\0';

    /* 释放栈空间 */
    free(dirStack);

    return res;
}