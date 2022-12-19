```
typedef struct {
    int name;//key
    int val;
    int prior;
    int time;
    UT_hash_handle hh;
} LFUCache;
int max = 0;
LFUCache *g_trunk = NULL;

LFUCache *Find_INT(int name) {
    LFUCache *s = NULL;
    HASH_FIND_INT(g_trunk, &name, s);
    if (s != NULL) {
        s->prior++;
        s->time++;
    }
    return s;
}

void Add_INT(int name, int value) {
    LFUCache *s = (LFUCache *) malloc(sizeof(LFUCache));
    s->name = name;
    s->val = value;
    s->time = 0;
    s->prior = 0;
    HASH_ADD_INT(g_trunk, name, s);
}

void Delete(int name) {
    LFUCache *s = Find_INT(name);
    if (s != NULL) {
        HASH_DEL(g_trunk, s);
        free(s);
    }
}

void DeleteAll() {
    LFUCache *cur = NULL;
    LFUCache *tmp = NULL;
    HASH_ITER(hh, g_trunk, cur, tmp)
    {
        HASH_DEL(g_trunk, cur);
        free(cur);
    }
}

int HashCount() {
    return HASH_COUNT(g_trunk);
}

int IdSort(LFUCache *a, LFUCache *b) {
    if(a->prior != b->prior) {
        return (a->prior - b->prior);
    } else {
        return (b->time - a->time);
    }
}

void SortById() {
    HASH_SORT(g_trunk, IdSort);
}

LFUCache *lFUCacheCreate(int capacity) {
    LFUCache *g_trunk_1 = g_trunk;
    max = capacity;
    return g_trunk_1;
}

int lFUCacheGet(LFUCache *obj, int key) {
    if (max == 0) return -1;
    LFUCache *tt = Find_INT(key);
    if (tt == NULL) {
        return -1;
    }
    LFUCache *cur = NULL;
    LFUCache *tmp = NULL;
    HASH_ITER(hh, g_trunk, cur, tmp) {
        cur->time++;
    }
    tt->time = 0;
    return tt->val;
}

void lFUCachePut(LFUCache *obj, int key, int value) {
    if (max == 0) return 0;
    int cnt = HashCount();
    LFUCache *s = NULL;
    s = Find_INT(key);
    if (s == NULL) {
        if (cnt < max) {
            Add_INT(key, value);
        } else {
            SortById();
            Delete(g_trunk->name);
            Add_INT(key, value);
        }
    } else {
        s->val = value;
        s->prior++;
        s->time++;
    }
}

void lFUCacheFree(LFUCache *obj) {
    if (max == 0) return;
    DeleteAll();
}
```
