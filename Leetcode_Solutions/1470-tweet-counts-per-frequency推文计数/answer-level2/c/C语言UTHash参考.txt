### 解题思路
1.UTHash存储用户，数组存储用户的发文时间，
2.返回结果是，每个时间段相当于桶，将用户放到不同的桶中即可。
### 代码

```c

struct TimeList{
    int time;
    struct TimeList *next;
};
struct TweetRecord{
    char *name;
    struct TimeList *tmList;
    UT_hash_handle hh;
};
typedef struct {
    struct TweetRecord *twMap;
} TweetCounts;

void AddTWRecord(char* name, int time, struct TweetRecord **twMap) {
    struct TweetRecord *s = malloc(sizeof(struct TweetRecord));
    s->name = malloc(strlen(name) + 1);
    strcpy(s->name, name);
    struct TimeList *node = malloc(sizeof(struct TimeList));
    node->time = time;
    node->next = NULL;
    s->tmList = node;
    HASH_ADD_KEYPTR( hh, *twMap, s->name, strlen(s->name), s );
}

TweetCounts* tweetCountsCreate() {
    TweetCounts* obj = malloc(sizeof(TweetCounts));
    if (obj == NULL){
        return NULL;
    }
    obj->twMap = NULL;
    return obj;
}

void tweetCountsRecordTweet(TweetCounts* obj, char * tweetName, int time) {
    struct TweetRecord *s = NULL;
    HASH_FIND_STR( obj->twMap, tweetName, s);
    if (s != NULL){
        struct TimeList *node = malloc(sizeof(struct TimeList));
        node->time = time;
        node->next = s->tmList;
        s->tmList = node;
    } else {
        AddTWRecord(tweetName, time, &obj->twMap);
    }
}

int* tweetCountsGetTweetCountsPerFrequency(TweetCounts* obj, char * freq, char * tweetName, int startTime, int endTime, int* retSize) {
    struct TweetRecord *s = NULL;
    HASH_FIND_STR( obj->twMap, tweetName, s);
    if (s == NULL){
        return NULL;
    }
    int freqVal = 1;
    if (*freq == 'm'){
        freqVal = 60;
    } else if (*freq == 'h'){
        freqVal = 60*60;
    } else if (*freq == 'd'){
        freqVal = 60*60*24;
    }
    //计算返回的数目
    *retSize = (endTime - startTime) / freqVal + 1;
    int *ans = malloc(sizeof(int) * (*retSize));
    memset(ans, 0, sizeof(int) * (*retSize));
    struct TimeList *p = s->tmList;
    while(p != NULL){
        int time = p->time;
        if (time >= startTime && time <= endTime){
            time -= startTime;
            ans[time/freqVal]++;
        }
        p = p->next;
    }
    return ans;
}

void tweetCountsFree(TweetCounts* obj) {

}


/**
 * Your TweetCounts struct will be instantiated and called as such:
 * TweetCounts* obj = tweetCountsCreate();
 * tweetCountsRecordTweet(obj, tweetName, time);
 
 * int* param_2 = tweetCountsGetTweetCountsPerFrequency(obj, freq, tweetName, startTime, endTime, retSize);
 
 * tweetCountsFree(obj);
*/
```