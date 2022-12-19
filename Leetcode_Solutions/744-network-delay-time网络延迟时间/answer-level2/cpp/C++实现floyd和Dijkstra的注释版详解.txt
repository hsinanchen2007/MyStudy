743.网络延迟时间 中等
一共N个点，求第K个点发出的信息传播到所有结点所需要的最大延迟。times存放着从times[0]传播到times[1]所需要的时间times[2].
这个要看一下，涉及到网络最短路径知识点，floyd和dijkstra。
只有五行的 Floyd 最短路算法，它可以方便的求得任意两点的最短路径，这称为“多源最短路”。 dijkstra是指定一个点（源点）到其余各个顶点的最短路径，也叫做“单源最短路径”。
```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //第一步：构造邻接矩阵，注意，是有向图，未连接部分距离为infinity
        vector<vector<int>> adjmap(N,vector<int>(N,1<<30-1));
        for(auto it:times){
            adjmap[it[0]-1][it[1]-1] = it[2];
            //adjmap[it[1]-1][it[0]-1] = it[2];注意，本题是有向边
            adjmap[it[0]-1][it[0]-1] = 0;
            adjmap[it[1]-1][it[1]-1] = 0;
        }
        //第二步：构造所有点与K点的距离，用邻接矩阵的第K-1行来初始化
        vector<int> distancetoK(N);
        distancetoK = adjmap[K-1];
        //第三步：使用book数组来记录哪些点与K的最短距离已经确定了，一旦确定了标记为0
        vector<int> book(N,0);
        book[K-1] = 1;
        int neighbor = 0;
        //第四步：Dijikstra寻找当前某一点与K的最短距离
        for(int index=0;index<N;index++){
            int min = 1<<30-1;//每次寻找一定要在这里初始化min，不能放在循环外面
            //第五步：在当前的distancetoK且没有被标记的结点中，寻找最短的结点
            for(int i = 0;i<N;i++){
                if(distancetoK[i]<min && book[i]==0) min = distancetoK[i],neighbor = i;
            }
            //第六步：这个结点与K的距离确定了，所以它标记为1
            book[neighbor] = 1;
            //第六步：判断剩下还没有和K点确定距离的那些点，是绕一圈与K更近还是直接走更近，返回第五步
            for(int j=0;j<N;j++){
                if(distancetoK[j]>distancetoK[neighbor]+adjmap[neighbor][j]) 
                    distancetoK[j] = distancetoK[neighbor]+adjmap[neighbor][j];
            }
        }
        int max = 0;
        //第七步：在distancetoK中的最长路径就是本题中的最大网络延迟
        for(int it:distancetoK) max = (max<it)?it:max;
        //第八步：如果最大路径的长度为infinity，则返回-1
        return (max==1<<30-1)?-1:max;
    }
};

```
Dijikstra是寻找其他点分别与某一点的最小路径，
它的思路是有一个标记book，已经确定最小路径的结点标记为1，自己到自己是自然1.
然后有一个邻接矩阵，注意，之前其他题用的是邻接表(比较稀疏)，像这种找最短路径的题用邻接矩阵。
然后再建立一个数组distance，用邻接矩阵的第K行初始化，记录各个点到K的最小距离。
在最小距离数组distance中，找到离K最近的点A，A与K的距离不可能有其他更小的可能了，所以A与K的距离确定了，它的book标记改为1；
在邻接表的第A行找到与A相连的每一个点，判断这些点与K的距离是直接相连更近还是经过A绕一下更近，然后用较小的值更新最小距离数组，返回上一步；
每经过一次循环，都是在判断 K与某个点的直接距离 更近，还是 K经过ABC..等一系列最短距离的点绕一下 更近，然后再更新最小距离数组。

```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //第一步：构造邻接矩阵，注意，是有向图，未连接部分距离为infinity
        vector<vector<int>> adjmap(N,vector<int>(N,1<<10-1));
        for(auto it:times){
            adjmap[it[0]-1][it[1]-1] = it[2];
            //adjmap[it[1]-1][it[0]-1] = it[2];注意，本题是有向边
            adjmap[it[0]-1][it[0]-1] = 0;
            adjmap[it[1]-1][it[1]-1] = 0;
        }
        //第二步：根据Floyd更新邻接矩阵
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(adjmap[i][j]>adjmap[i][k]+adjmap[k][j]) adjmap[i][j]=adjmap[i][k]+adjmap[k][j];
                }
            }
        }
        int max = 0;
        //第三步：在distancetoK中的最长路径就是本题中的最大网络延迟
        for(int it:adjmap[K-1]) max = (max<it)?it:max;
        //第四步：如果最大路径的长度为infinity，则返回-1
        return (max==1<<10-1)?-1:max;
    }
};

```
Floyd是确定所有点两两之间的最短距离。对于图中某两个点(两重循环)，判断他俩直接相连更近还是经过点A绕一下更近，然后更新邻接矩阵；然后在判断从B绕一下，C绕一下，怎么样更近一些...，直到在所有点都绕一下，因此是三重循环。思想是动态规划。很明显这种解法更简单。

