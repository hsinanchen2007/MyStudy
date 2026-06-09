### 解题思路
并查集的应用。

### 代码

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int a[MAX],pre[MAX];
int group[MAX];

int find(int x)
{
    if(x!=pre[x])
    //找到其祖先节点 
     pre[x] = find(pre[x]);  
    //由父节点继续向上递归查询 ,并将其父节点变成找到的 
    return pre[x]; 
}
void merge(int x,int y)
{
    //分别查询两点的祖先节点。 
    int prex = find(x);
    int prey = find(y);
    //如果二者的祖先节点不一致，那么任意让二者中某一个认另一个为祖先，保证同集合。
    if(prex == prey)
    {
        return ;
    } 
    //应该是祖先节点进行组合。而不是当前节点！ 
    pre[prey] = prex;  
    a[prex] += a[prey];     
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){

	for(int i = 0; i < MAX;i++)
	{
		pre[i] = i;
        a[i] = i;
        group[i] = 0;
	}
    int total = 0;
    int duoyu = 0;
    for(int i = 0; i < connectionsSize ;i ++)
    {
        int t1 = find(connections[i][0]);
        int t2 = find(connections[i][1]);
        if(t1 == t2) 
        {
           duoyu++;
        }
        merge(connections[i][0],connections[i][1]);
                
    }
    int myset = 0;
    for(int i = 0; i < n ;i ++)
    {
        if(pre[i] == i) {
           myset++;
        }

    }
    printf("%d    %d\r\n", myset, duoyu);

    if(myset - 1 > duoyu) { return -1;}
    return myset-1;




}
```