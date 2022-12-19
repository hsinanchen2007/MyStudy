### 解题思路
给定从 0 到 n-1 标号的 n 个结点，和一个无向边列表（每条边以结点对来表示），请编写一个函数用来判断这些边是否能够形成一个合法有效的树结构。

示例 1：

输入: n = 5, 边列表 edges = [[0,1], [0,2], [0,3], [1,4]]
输出: true




并  union    将两个节点并到一个集合里，
查  find     找该节点对应的集合（代表），这里就是根； 
             如果两个节点的根相同 就是有环了
             最后应该所有节点共一个根， 否则就是森林了
集  S        

### 代码

```c
int S[10000];

int find(int n){
    if(S[n] == n)
        return n;
    else
        return find(S[n]);
}

void union_xy(int x, int y){
    if(y == S[y]){
        S[y] = x; 
    }else{
        S[x] = y;
    }
}

bool validTree(int n, int** edges, int edgesSize, int* edgesColSize){
    int i,x,y;

    //初始化每个节点额集合（根） 是自己
    for(i=0;i<n;i++){
        S[i] = i;
    }
    for(i=0;i<edgesSize;i++){
        x = find(edges[i][0]);
        y = find(edges[i][1]);
        if(x == y)
            return false;
        union_xy(x,y);
    }

    for(i=1;i<n;i++){
        if(find(i) != find(0))
            return false;
    }
    return true;
}
```