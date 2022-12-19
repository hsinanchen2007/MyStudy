### 解题思路
正反遍历，关键思路清晰

### 代码

```c
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    if((distance == NULL) || (distanceSize == 0)){
        return 0;
    }
    if(start > destination){
        int tmp = start;
        start = destination;
        destination = tmp;
    }
    int disCnt0 = 0;
    for(int i = start; i < destination;++i){
        disCnt0 += distance[i];
    }
    int disCnt1 = 0;
    for(int i = destination; i < distanceSize; ++i){
        disCnt1 += distance[i];
    }
    for(int i = 0;i < start;++i){
        disCnt1 += distance[i];
    }

    return disCnt0 < disCnt1 ? disCnt0 : disCnt1;
}
```