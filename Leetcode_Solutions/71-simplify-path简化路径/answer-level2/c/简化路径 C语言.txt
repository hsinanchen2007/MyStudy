
栈实现：
1. 申请临时缓存暂存路径，并路径分割为以 \0 结束的子串。
2. 将路径转化为栈，'.'忽略，'..' 出栈， 其他入栈。
3. 从栈底遍历输出（利用原来的输入作为输出）。

是不是很简单？

```c

typedef struct _stack {
    int len;
    int used;
    char **p;
}stack;

int stack_init(stack *s, int len) {
    if (s == NULL) {
        return -1;        
    }
    s->p = (char **) calloc(sizeof(char *), len);
    s->len = len;
    s->used = 0;
    return (s->p == NULL) ? -1 : 0;
}

int stack_free(stack *s) {
    if ( s == NULL || s->p == NULL) {
        return -1;
    }
    free(s->p);
    s->p = NULL;
    s->len = s->used = 0;
    return 0;
}

int stack_push(stack *s, char* p) {
    if ( s == NULL || s->p == NULL) {
        return -1;
    }
    if (s->used >= s->len) {
        return -1;
    }
    s->p[s->used] = p;
    s->used++;
    return 0;
}

int stack_pop(stack *s, char** p) {
    if ( s == NULL || s->p == NULL) {
        return -1;
    }
    if (s->used == 0) {
        return -1;
    }
    *p = s->p[s->used];
    s->used--;
    return 0;
}

char ** split_init(char *path, int *count) {
    char **paths = (char **)calloc(sizeof(char *), strlen(path));
    *count = 0;
    for (int i = 0; path[i] != 0;){
        while (path[i] == '/') {
            path[i] = 0;
            i++;
        }
        if (path[i] == 0) {
            return paths;
        }
        paths[*count] = path + i;
        while (path[i] != '/' && path[i] != 0) {
            i++;
        }
        *count += 1;
    }
    return paths;
}

void split_free(char **p) {
    if (p == NULL)
        return;
    free(p);
}

void paths_to_stack(char** paths, int count, stack* s) {
    char *p = NULL;
    for (int i = 0; i < count; i++) {
        if(strcmp(paths[i],".") == 0) {
            continue;
        }            
        if(strcmp(paths[i],"..") == 0) {
            stack_pop(s,&p);
        } else {
            stack_push(s, paths[i]);
        }
    }
}

void get_simplify_path(stack* s, char* out, int max_len) {
    strcpy(out, "/");
    for (int i = 0; i < s->used; i++) {
        strcat(out, s->p[i]);
        printf("[%d/%d]%s\n", i, s->used, out);
        if (i < s->used - 1) {
            strcat(out, "/");
        }
    }
}

char * simplifyPath(char * path){
    int count, max_len;
    stack s;
    char **paths;
    char* temp = (char*)malloc(strlen(path)+1);
    strcpy(temp,path);
    max_len = strlen(path);
    stack_init(&s, max_len);
    paths = split_init(temp, &count);
    
    paths_to_stack(paths, count, &s);
    get_simplify_path(&s, path, max_len);
        
    split_free(paths);
    stack_free(&s);
    free(temp);
    return path;
}


```
