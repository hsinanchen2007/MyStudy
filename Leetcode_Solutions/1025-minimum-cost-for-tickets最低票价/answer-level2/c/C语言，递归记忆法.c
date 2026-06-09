4ms，C语言 递归公式：dp(i)=min(dp(i+1)+costs[0],dp(i+7)+costs[1],dp(i+30)+costs[2])

```
#define TICKET_TYPE 3
#define MIN(a, b) ((a) < (b)) ? (a) : (b);
#define MAX_COST (365*1000)

int tickDays[TICKET_TYPE] = {1, 7, 30}; // 每种票对应的天数

int getMinCost(int* days, int* daysMinCost, int daysSize, int beginDayIndex, int* costs)
{
    int minCost = MAX_COST; // 先默认最大
    int beginDay = days[beginDayIndex];
    for (int i = TICKET_TYPE - 1; i >= 0; i--) {
        int cost = costs[i];

        // 遍历后面需要继续买票的那天，并计算最小花费
        for (int j = beginDayIndex + 1; j < daysSize; j++) {
            if (days[j] - beginDay >= tickDays[i]) {
                // 如果之前已经计算过，直接复用
                if (daysMinCost[j]){
                    cost += daysMinCost[j];
                    break;
                }
                
                // 如果没有计算过，递归计算
                cost += getMinCost(days, daysMinCost, daysSize, j, costs);
                break;
            }
        }
        
        minCost = MIN(cost, minCost);
    }
    
    if (daysMinCost[beginDayIndex] == 0)
    {
        daysMinCost[beginDayIndex] = minCost;
    }
    
    return minCost; 
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
{
    if (daysSize == 0) {
        return 0;
    }

    // 记录每天的最小花费，避免重复查找
    int *daysMinCost = (int *)malloc(daysSize * sizeof(int));
    memset(daysMinCost, 0, daysSize * sizeof(int));
    
    int minCost =  getMinCost(days, daysMinCost, daysSize, 0, costs);
    
    free(daysMinCost);
    
    return minCost;
}
```
