### 解题思路
执行用时击败96.17%，感觉效率还不错
根据图论定理，**在平面图中，能增加平面数的边必然是弦**（即连通分支内的两点相连）；
同时，根据题目的设定，**加的弦不会和其他的边相交**，根据图论定理，平面数+1；
所以我们的目标就是判断每次读进来的斜杠的两个点是否属于同一个连通分支：
1）如果属于同一个连通分支，平面数+1；
1）如果不属于同一个连通分支，就把这两个连通分支连在一起。
过程：
1、初试化father数组，即每个节点的源节点（并查集的基本知识）；
2、把N*N的网格的四条边先连成一个连通分支（通过father数组即可）；

3、循环：
1）每次读入一个字符，
2）如果是空格，up和down就往前一步；
3）如果是斜杠，就判断右上和左下的节点是否在一个连通分支内，判定通过平面数+1；
4）如果是反斜杠，就判断左上和右下的节点是否在一个连通分支内，判定通过平面数+1；
5）把斜杠连接的两个节点通过Union连入一个连通分支；

4、循环结束，返回平面数。
![WeChatb67c5ccdef7c477d516fbf55514d46ae.png](https://pic.leetcode-cn.com/d5409c2b37fa905abd4dd0e87ab6e150ba4c2a375c4053cc4d499956ceed82a4-WeChatb67c5ccdef7c477d516fbf55514d46ae.png)
举例说明：3*3的网格
1、初始化的时候，把0、1、2、3、4、8、12、7、11、15、13、14这四条边上的节点连在一起；
2、用up代表上方节点，down代表下方节点，循环的时候，每次往右平移up和down.



### 代码

```cpp
class Solution {
public:
    int father[1000];
    int regionsBySlashes(vector<string>& grid) {
        //用并查集，想象每个斜杠连接的是两个点，每次查询时，只需要判断连接的两个点是否father一样即可，一样就分割（区域+1），不一样就正常连接

        for(int i=0; i<1000; i++) father[i]=i;//初始化father数组
        //初始化第一行的连接
        for(int i=0; i<grid.size(); i++){
            Union(i, i+1);
        }
        //初始化最后一行的连接
        for(int i=(grid.size()+1)*grid.size(); i<(grid.size()+1)*grid.size()+grid.size(); i++){
            Union(i, i+1);
        }
        for(int i=0; i<(grid.size()+1)*grid.size();i+=grid.size()+1){
            Union(i, i+grid.size()+1);
        }
        //初始化最右边一列的连接
        for(int i=grid.size(); i<(grid.size()+1)*grid.size();i+=grid.size()+1){
            Union(i, i+grid.size()+1);
        }
        int re=1;
        for(int i=0; i<grid.size(); i++){
            int up=i*(grid.size()+1);
            int down=up+grid.size()+1;
            string s=grid[i];
            for (int j=0; j<s.size(); j++){//每次读一个字符，空格或者斜杠
                if (s[j]==' '){
                    up++;//平移up和down
                    down++;
                    continue;
                }
                else if (s[j]=='/'){//判断右上和左下的点是否是一个连通分支
                    if (findFather(up+1) == findFather(down)) re++;
                    Union(up+1, down);//两个点连在一起
                    up++;
                    down++;
                    continue;
                    
                }
                else if (s[j]=='\\'){//判断左上和右下的点是否是一个连通分支
                    if (findFather(up)==findFather(down+1)) re++;
                    Union(up, down+1);//两个点连在一起
                    up++;
                    down++;
                    continue;
                }

            }
        }
        return re;
    }
    void Union(int a, int b){
        int faA=findFather(a);
        int faB=findFather(b);
        if (faA != faB) father[faB]=faA;
    }
    int findFather(int x){
        int a=x;
        while(x!=father[x]) x=father[x];
        while(a != father[a]){
            int z=a;
            a=father[a];
            father[z]=x;
        }
        return x;
    }
};
```