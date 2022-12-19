#define MAXSIZE 3002

typedef struct {
    int nums[MAXSIZE];
    int begin;
    int end;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *list = (RecentCounter *)malloc(sizeof(RecentCounter));
    memset(list, 0, sizeof(RecentCounter));
    list->begin = 0;
    list->end = 0;
    return list;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->nums[(obj->end++) % MAXSIZE] = t;

    while ((t - obj->nums[(obj->begin) % MAXSIZE]) > 3000) {
        obj->begin++;
    }
    return obj->end - obj->begin;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/