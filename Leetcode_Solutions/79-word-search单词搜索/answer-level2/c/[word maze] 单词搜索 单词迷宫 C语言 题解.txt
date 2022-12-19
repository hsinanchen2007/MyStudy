
单词搜索：
1. 准备：创建一个简单的栈，长度与待寻找word一致就可以了。用于存放已经匹配的字母坐标。
2. 首先：以迷宫中每一个字母开始都有可能，两重循环遍历。
3. 递归：首字母匹配后，坐标压栈，依次向四周寻找下一个坐标，如果坐标合法，且下一个字母匹配，继续压栈，依次循环。
4. 结束：当word中所有字母匹配后，结束递归。

是不是很简单？ 代码离商用还有点距离，需要的话各位继续优化。

```c
#ifdef MY_DEBUG
#define LOG(fmt, args...) fprintf(stdout, fmt, ##args)
#else
#define LOG(fmt, args...)
#endif

typedef struct _pos {
    int r;
    int c;
}pos;

typedef struct _mark {
    int count;
    int used;
    pos *data;
}_mark;

static int row, col, word_len;
static char **maze;
static _mark mark;

void mark_init(_mark *mark, int len) {
    mark->data = (pos *)calloc(sizeof(pos), len);
    mark->count = len;
    mark->used = 0;
}

void mark_free(_mark *mark) {
    if (mark != NULL)
        free(mark->data);
    mark->data = NULL;
    mark->count = 0;
    mark->used = 0;
}

int mark_push(_mark *mark, int r, int c) {
    if (mark->used >= mark->count) {
        LOG("mark array overflow.\n");
        return -1;
    }
    pos *p = mark->data + mark->used;
    p->r = r;
    p->c = c;
    mark->used += 1;
    return 0;
}

pos mark_pop(_mark *mark) {
    
    if (mark->used == 0){
        pos p = {-1, -1};
        return p;
    }
    mark->used--;
    return mark->data[mark->used];
}

int mark_has(_mark *mark, int r, int c) {
    for (int i = 0; i < mark->used; i++) {
        if (mark->data[i].r == r && mark->data[i].c == c) {
            return 1;
        }
    }
    return 0;
}

void mark_clear(_mark *mark) {
    mark->used = 0;
}

#define FULL_MATCH  1
#define NOT_MATCH   0

static int get_next_direction(int *r, int *c, int dir) {
    switch (dir) {
        case 0: *c += 1; break;
        case 1: *r += 1; break;
        case 2: *c -= 1; break;
        case 3: *r -= 1; break;
        default: return -1;
    }
    return 0;
}

int find_word(const char *word, int r, int c, int index) {
    int ret, next_r, next_c;
    if (r >= row || c >= col || r < 0 || c < 0) {
        LOG("Ea%d(%d,%d) ", index, r, c);
        return NOT_MATCH;
    }
    if (mark_has(&mark, r, c)) {
        LOG("Eb%d.%c(%d,%d) ", index, word[index], r, c);
        return NOT_MATCH;
    }
    if (word[index] == maze[r][c]) {
        LOG("%d.%c(%d,%d) ", index, word[index], r, c);
        if (index == word_len - 1) {
            return FULL_MATCH;
        }
        mark_push(&mark, r, c);
        for (int d = 0; d < 4; d++)  {
            next_r = r, next_c = c;
            get_next_direction(&next_r, &next_c, d);
            ret = find_word(word, next_r, next_c, index+1);
            if (ret == FULL_MATCH) {
                return FULL_MATCH;
            }
        }
        mark_pop(&mark);
    }
    LOG("Ec%d.%c(%d,%d) ", index, word[index], r, c);
    return NOT_MATCH;
};

void display_path(_mark* mark) {
    if ( mark->used == 0) {
        return;
    }
    for (int i = 0; i < mark->used; i++) {
        pos *p = mark->data + i;
        printf("%c(%d, %d) ", maze[p->r][p->c], p->r, p->c);
    }
    printf("\n");
}

bool check_word(const char * word) {
    int ret;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            ret = find_word(word, r, c, 0);
            LOG("\n");
            if (ret == FULL_MATCH)
                return true;
            display_path(&mark);
            mark_clear(&mark);
        }
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    bool ret = false;
    maze = board;
    row = boardSize;
    col = *boardColSize;
    word_len =  strlen(word);
    if (row <= 0 || col <= 0 || word_len <= 0)
        return false;
    mark_init(&mark, word_len);
    if (mark.data == NULL)
        return false;
    ret = check_word(word);
    mark_free(&mark);
    return ret;
}

```
