### 解题思路
主要记录自己几个盲点
1. 这个边缘的列表这个表示法，第一次见，每一行代表一条边，【1,0】就是0指向1的边，所以，第一个for循环就是循环每一行的第一个位置，有多少次，入度为几
2. 第二点是第二个for，只有在你找到一个入度为0以后，才将i重置为-1，整个循环应该会进行的次数，是课程的总次数，但total如果不成环则相等，否则不相等

### 代码

```c
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
//判断是否成环
    int i,j;
    int visit[2000]={0},indegree[2000]={0},total=0;
    if(!prerequisitesSize||!prerequisitesColSize) return 1;
    for(i=0;i<prerequisitesSize;i++)
        indegree[prerequisites[i][0]]++;
    for(i=0;i<numCourses;i++){
        if(indegree[i]==0&&visit[i]==0){
            visit[i]=1;
            for(j=0;j<prerequisitesSize;j++){
                if(prerequisites[j][1]==i)
                    indegree[prerequisites[j][0]]--;
            }
            total++;
            i=-1;
        }
    }
    return numCourses==total;
}
```