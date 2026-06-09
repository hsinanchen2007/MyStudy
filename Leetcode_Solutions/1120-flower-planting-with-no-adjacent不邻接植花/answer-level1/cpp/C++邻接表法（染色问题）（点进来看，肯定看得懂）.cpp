### 解题思路
首先，使用邻接矩阵的话，亲测，会堆栈溢出，遂改为邻接表法。
1、根据paths建立邻接表；
2、默认所有的花园先不染色，即染0；
3、从第一个花园开始走，把与它邻接的花园的颜色从color{1,2,3,4}这个颜色集中删除；
4、删完了所有与它相邻的颜色，就可以把集合中剩下的颜色随机选一个给它了，为了简单，将集合中的第一个颜色赋给当前花园；
5、循环3和4到最后一个花园。

### 代码

```cpp
class Solution {
public:
    //static const int MAXV=10000;
    //int G[MAXV][MAXV]={0};
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> G[N];
        for (int i=0; i<paths.size(); i++){//建立邻接表
            G[paths[i][0]-1].push_back(paths[i][1]-1);
            G[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> answer(N,0);//初始化全部未染色
        for(int i=0; i<N; i++){
            set<int> color{1,2,3,4};
            for (int j=0; j<G[i].size(); j++){
                color.erase(answer[G[i][j]]);//把已染过色的去除
            }
            answer[i]=*(color.begin());//染色
        }
        return answer;
    }
};
```