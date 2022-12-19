### 解题思路
用一个flow数组记录 自己所在的集合的序号
时间不行、空间还行
![image.png](https://pic.leetcode-cn.com/155b4da6d1cf75c7a42556e32fc8bc2f1fdcb98cc24855913eea41fd329fd8a5-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    * returnSize=2;
    int numOfVecs=3;
    int i;
    for(i=0;i<edgesSize;i++)
        if(edges[i][1]>numOfVecs)
            numOfVecs=edges[i][1];

    int *flow=(int *)malloc(sizeof(int)*numOfVecs);
    int *result=(int *)malloc(sizeof(int)*2);
    for(i=0;i<numOfVecs;i++)
        flow[i]=i;
 
    for(i=0;i<edgesSize;i++)
        if(flow[edges[i][0]-1]!=flow[edges[i][1]-1]){
            int min=flow[edges[i][0]-1]<flow[edges[i][1]-1]?flow[edges[i][0]-1]:flow[edges[i][1]-1];
            int max=flow[edges[i][0]-1]>=flow[edges[i][1]-1]?flow[edges[i][0]-1]:flow[edges[i][1]-1];
            int j;
            for(j=0;j<numOfVecs;j++){
                if(flow[j]==max)
                    flow[j]=min;
            }
        }else{
            result[0]=edges[i][0];
            result[1]=edges[i][1];
        }
     
    return result;
 
}
```