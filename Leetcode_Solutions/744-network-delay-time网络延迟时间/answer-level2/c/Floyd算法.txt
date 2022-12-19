```
#define MAX_TIME 65535
#define MAXNUMS 101
int g_Network[MAXNUMS][MAXNUMS] = {0};
static void initNetwork(int N){
    for(int i = 1; i <= N; i++){
        g_Network[i][i] = 0;
        for(int j = 1; j <= N; j++){
            if(i != j){
                 g_Network[i][j] = MAX_TIME;
            }
        }
    }
}

static void setNetwork(int** times, int timesSize){
    for(int i = 0; i < timesSize; i++){
        g_Network[times[i][0]][times[i][1]] = times[i][2];
    }
}

static void updateFloyd(int N){
    int tmp = 0;
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){ 
            for(int j = 1; j <= N; j++){
                tmp = g_Network[i][k] + g_Network[k][j];
                if(g_Network[i][j] > tmp){
                    g_Network[i][j] = tmp;
                }
            }
        }
    }
}

static int getMinTime(int N, int K){
    int minTime = 0;
    for(int i = 1; i <= N; i++){
        if(g_Network[K][i] ==  MAX_TIME) {
            return -1;
        }
        if(minTime < g_Network[K][i]){
            minTime = g_Network[K][i];
        }
    }
    return minTime;
}

static void clearNetwork(){
    for(int i = 0; i < MAXNUMS; i++){
        memset(g_Network[i], 0, sizeof(MAXNUMS*sizeof(int)));
    }
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    initNetwork(N);
    setNetwork(times, timesSize);
    updateFloyd(N);
    int minTime = getMinTime(N, K);
    clearNetwork();
    return minTime;
}

```
