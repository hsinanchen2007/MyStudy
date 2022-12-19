
1：BFS 方法,性能比较好：
![image.png](https://pic.leetcode-cn.com/80444fa28a76e9503e6bd76ce388a3704fdbbfa6cb4a4b235bbb90307141e9db-image.png)

```
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define MAX_FLIGHT_NUM 100
int RefreshNextPathPrice(int startpos, int flightMatrix[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM],
    int pathminTotalPrice[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM], int curPathCount, int NextStartArr[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM])
{
    int curFlightPrice = 0;
    int lastTotalPrice = 0;
    int curPathminTotalPrice = 0;

    for (int j = 0; j < MAX_FLIGHT_NUM; j++) {
        curFlightPrice = flightMatrix[startpos][j];
        if (curFlightPrice != 0) {
            lastTotalPrice = (curPathCount - 1) >= 0 ? pathminTotalPrice[startpos][curPathCount - 1] : 0;
            curPathminTotalPrice = pathminTotalPrice[j][curPathCount];
            if (curPathminTotalPrice == 0 || curPathminTotalPrice > curFlightPrice + lastTotalPrice) {
                pathminTotalPrice[j][curPathCount] = curFlightPrice + lastTotalPrice;
                NextStartArr[curPathCount][j] = 1;
            }
        }
    }
    return 0;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K) {

    int i;
    int j;
    int iter = 0;
    int minTotalPrice = 0;
    int curPathPrice = 0;

    int nextStartArr[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM] = { 0 };
    int flightMatrix[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM] = { 0 };
    int dstPathminTotalPrice[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM] = { 0 };  // 维度 是 （dst, k, minTotalPrice）

    if (n == 0 || flights == NULL || flightsSize == 0) {
        return -1;
    }

    for (i = 0; i < flightsSize; i++) {
        flightMatrix[flights[i][0]][flights[i][1]] = flights[i][2];
    }

    nextStartArr[0][src] = 1;
    for (iter = 0; iter <= K; iter++) {
        i = 0;
        while (i < MAX_FLIGHT_NUM) {
            if (nextStartArr[iter][i] == 1 && i != dst) {
                RefreshNextPathPrice(i, flightMatrix, dstPathminTotalPrice, iter + 1, nextStartArr);
            }
            i++;
        }
    }

    for (i = 0; i <= K + 1; i++) {
        curPathPrice = dstPathminTotalPrice[dst][i];
        if (curPathPrice != 0) {
            minTotalPrice = (minTotalPrice == 0) ? curPathPrice : MIN(curPathPrice, minTotalPrice);
        }
    }

    return minTotalPrice == 0 ? -1 : minTotalPrice;
}
```
2: DFS 方法

```
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define MAX_FLIGHT_NUM 100
int RefreshPathPrice(int startpos, int flightMatrix[MAX_FLIGHT_NUM ][MAX_FLIGHT_NUM ],  
            int pathminTotalPrice[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM],  int curPathCount,  int maxPath)
{
    int curFlightPrice = 0;
    int lastTotalPrice = 0;
    int curPathminTotalPrice = 0;

    for (int j = 0; j < MAX_FLIGHT_NUM; j++) {
        curFlightPrice = flightMatrix[startpos][j];
        if (curFlightPrice != 0) {
            lastTotalPrice = (curPathCount - 1) >= 0 ? pathminTotalPrice[startpos][curPathCount - 1] : 0;
            curPathminTotalPrice = pathminTotalPrice[j][curPathCount];
            if (curPathminTotalPrice == 0 || curPathminTotalPrice > curFlightPrice + lastTotalPrice)  {
                 pathminTotalPrice[j][curPathCount] =  curFlightPrice + lastTotalPrice;
                 if (curPathCount + 1 <= maxPath) {
                    RefreshPathPrice(j, flightMatrix, pathminTotalPrice, curPathCount + 1, maxPath);
                 }
            } 
        }
    }
    return 0;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){

    int i;
    int minTotalPrice = 0;
    int curPathPrice = 0;

    int flightMatrix[MAX_FLIGHT_NUM ][MAX_FLIGHT_NUM] = { 0 };
    int dstPathminTotalPrice[MAX_FLIGHT_NUM][MAX_FLIGHT_NUM] = { 0 };  // 维度 是 （dst, k, minTotalPrice）

    if (n == 0 || flights == NULL || flightsSize == 0) {
        return -1;
    }

    for (i = 0; i < flightsSize; i++) {
        flightMatrix[flights[i][0]][flights[i][1]] = flights[i][2];
    }

    RefreshPathPrice(src, flightMatrix, dstPathminTotalPrice,  0,  K);
    for (i = 0; i <= K; i++) {
        curPathPrice = dstPathminTotalPrice[dst][i];
        if (curPathPrice != 0) {
            minTotalPrice = (minTotalPrice == 0) ? curPathPrice : MIN(curPathPrice, minTotalPrice);
        }
    }

    return minTotalPrice == 0 ? -1 : minTotalPrice;
}
```
