### 解题思路
用长为60的数组记录时长模60，结果相加为60的两个数和结果都为0的数为所求
### 代码

```c
int numPairsDivisibleBy60(int* time, int timeSize){
    int a[60],i,t,num=0;
    for(i=0;i<60;i++)a[i]=0;
    for(i=0;i<timeSize;i++){
            t=time[i]%60;
            if(t!=0)num+=a[60-t];
            else num+=a[0];
            a[t]++;
    }//for
    return num;
}
```