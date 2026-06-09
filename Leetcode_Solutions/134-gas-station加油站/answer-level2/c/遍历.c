### 解题思路
此处撰写解题思路

### 代码

```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    if(gasSize==1){
        if(gas[0]>=cost[0]) return 0;
        else return -1;
    }
    int i,value,visit,j;
    for(i=0;i<costSize;i++){
        if(gas[i]>=cost[i]){
            value=gas[i]-cost[i];
            visit=1;
            if(i==costSize-1) j=0;
            else j=i+1;
            for(;j<costSize;j++){
                if(value+gas[j]<cost[j]){
                    if(i<j)
                        i=j;
                    break;
                } 
                visit++;
                value+=gas[j]-cost[j];
                if(visit==costSize) return i;
                if(j==costSize-1) j=-1;
            }
        }
        //printf("%d %d\n",i,j);
    }
    return -1;
}
```