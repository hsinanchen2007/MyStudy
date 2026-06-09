### 解题思路
按照end排序，统计end之前的个数，如果下一个begin==end，则先下车。

### 代码

```c
int comparearry(const void *a, const void * b)
{
    int *aa = *(int **)a;
    int *bb = *(int **)b;

    return aa[2] - bb[2];
}

int carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){


    if(trips == 0 || tripsSize==0) {
        return 0;
    }
    qsort(trips,tripsSize,sizeof(int *),comparearry);
    for(int i=0;i<tripsSize; i++)
    {
        for(int k=0; k<*tripsColSize; k++) {
            printf(" %d ", trips[i][k]);
        }
        printf("\r\n");
    }
    int visit[tripsSize] ;
    for(int i = 0 ; i < tripsSize; i++)
    {
        visit[i] = 0;
    }
    //算法对于区间中的每个最早结束的end，找到与end相交的所有begin大于end的线段，并累加他们的值，如果sum <=capcity,则为TRUE，继续下一个end节点。如果sum>capcity,说明没法装了。
    //同时把相交的集合设置为访问状态。

    int curcap = trips[0][0];
    int end = trips[0][2];
    int sum = 0;

    for(int i = 0; i < tripsSize; i++) {

        for(int j = i; j < tripsSize; j++) {

            if(trips[j][1] < end && !visit[j])
            {
                sum += trips[j][0];
                visit[j] = 1;
            }
        }
        if(sum > capacity) {
            return 0;
        }
        sum -= trips[i][0]; //当前的下车
        if(i+1 < tripsSize) {
            end = trips[i+1][2];
        }

    }
    return 1;
    //下个end时，把第一个end的人员下车，走步骤1.

    //所有元素遍历完成，返回TRUE
}
```