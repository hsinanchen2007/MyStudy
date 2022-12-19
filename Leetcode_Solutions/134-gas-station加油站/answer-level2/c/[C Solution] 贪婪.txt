### 解题思路
此处撰写解题思路

### 代码

```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int currSum = 0,  totalSum = 0 , startIdx = 0 ;
    for(int i = 0 ; i < gasSize ; i++){
        totalSum += gas[i] - cost[i];
        currSum += gas[i] - cost[i];
        if(currSum < 0){
            startIdx = i + 1;
            currSum = 0;
        }
    }
    return totalSum >= 0 ? startIdx : -1;
}
```