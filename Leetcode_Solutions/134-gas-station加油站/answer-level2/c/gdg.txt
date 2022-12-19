### 解题思路
此处撰写解题思路

### 代码

```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int i,curr,j,flag;
    for(i=0;i<gasSize;i++){
        flag=1;
        if(gas[i]>=cost[i]){
            flag=0;
            curr=gas[i]-cost[i];
            j=i+1;
            if(j>=gasSize) j=0;
            while(j!=i){
                curr+=gas[j]-cost[j];
                if(curr<0){
                    flag=1;
                    break;
                }
                ++j;
                if(j>=gasSize) j=0;
            }
        }
        if(flag==0) return i;
    }

    return -1;
}
```