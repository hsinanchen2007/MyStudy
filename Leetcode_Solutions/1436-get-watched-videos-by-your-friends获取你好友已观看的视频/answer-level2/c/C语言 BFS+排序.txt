![竞赛.png](https://pic.leetcode-cn.com/62235da458b05a8fc6318847667a7c64bd8ce1ebfa4e875904790e514cdd7b8a-%E7%AB%9E%E8%B5%9B.png)
主要是将题目意图看清楚，朋友的朋友不能包含level前面的朋友，不理解该语句的直接看代码。
typedef struct tagRecord {
    int num;
    char* tmp;
}RECORD;

#define MAX_VIDERO 10001
#define MAX_FRIEND 101

int g_riend[MAX_FRIEND] = {0};
int g_loop = 0;
char** g_ret;
RECORD* g_record = NULL;

int InitGlobalVar()
{
    memset(g_riend, 0, sizeof(int) * MAX_FRIEND);

    // malloc
    g_ret = malloc(sizeof(char*) * MAX_VIDERO);
    if (g_ret == NULL) {
        return 0;
    }
    memset(g_ret, 0 , sizeof(char*) * MAX_VIDERO);
    g_loop = 0;
    g_record = malloc(sizeof(RECORD)*MAX_VIDERO);
    if (g_record == NULL) {
        return 0;
    }
    memset(g_record, 0, sizeof(RECORD) * MAX_VIDERO);
    return 1;
}

void FindLevelFriend(int* friend, int id, int level, int** friends, int* friendsColSize) 
{
    if(level == 1) {
        for (int i = 0; i < friendsColSize[id]; i++) {
            if(friend[friends[id][i]] == 0) {
                g_riend[friends[id][i]] = 1;
            } else {
                g_riend[friends[id][i]] = 0;
            }
        }
        return;
    }
    friend[id] += 1;
    for (int i = 0; i < friendsColSize[id]; i++) {
        friend[friends[id][i]] += 1;
    }
    
    for (int i = 0; i < friendsColSize[id]; i++) {
        FindLevelFriend(friend, friends[id][i], level - 1, friends, friendsColSize);
    }
    return;
}


int FindSameVideos(char* videoName)
{        
    for(int i = 0; i< g_loop; i++) {
        if(strcmp(g_record[i].tmp, videoName) == 0) {
            g_record[i].num += 1;
            return 0;
        }
    }
    return 1;
}

void InsertVideo(char* videoName)
{
    int pos = g_loop;

    g_record[pos].tmp = malloc(sizeof(char) * (strlen(videoName) + 1 ));
    if(g_record[pos].tmp == NULL) {
        return;
    }
    g_record[pos].num = 1;
    memcpy(g_record[pos].tmp, videoName, strlen(videoName));
    g_record[pos].tmp[strlen(videoName)] = 0;
    g_loop++;
    return;
}
void GetFriendVideos(char ** watchedVideos, int watchedVideosSize)
{
    for(int i = 0; i < watchedVideosSize; i++) {
        if (1 == FindSameVideos(watchedVideos[i])) {
            InsertVideo(watchedVideos[i]);
        }
    }
    return;
}

int CmpStr(const void* a, const void* b)
{
    RECORD tmpA = *(RECORD*)a;
    RECORD tmpB = *(RECORD*)b;

    if(tmpA.num == tmpB.num) {
        return strcmp(tmpA.tmp,tmpB.tmp);
    } else {
        return tmpA.num - tmpB.num;
    }
}

char ** watchedVideosByFriends(char *** watchedVideos, int watchedVideosSize, int* watchedVideosColSize, int** friends, int friendsSize, int* friendsColSize, int id, int level, int* returnSize){
    int friend[MAX_FRIEND] = {0};
    
    *returnSize = 0;
   
    // Init global var
    InitGlobalVar();
    
    // GetAllFriend
    FindLevelFriend(friend, id, level, friends, friendsColSize);
    
    // out of self
    for (int i = 0; i < friendsSize; i++) {
        if(g_riend[i] == 0 || i == id) {
            continue;
        }
        GetFriendVideos(watchedVideos[i], watchedVideosColSize[i]);     
    }

    // sort result
    qsort(g_record, g_loop, sizeof(RECORD), CmpStr);

    for(int i = 0; i < g_loop; i++) {
        g_ret[i] = g_record[i].tmp;
    }

    free(g_record);
    *returnSize = g_loop;
    return g_ret;
}