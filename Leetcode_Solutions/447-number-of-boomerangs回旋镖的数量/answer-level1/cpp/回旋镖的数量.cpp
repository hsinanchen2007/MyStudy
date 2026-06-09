战胜91.3%
思路:遍历每个节点开头的线段,用unordered_map记录每种长度的线段数量,每次增加一种长度的数量,若已经有等长线段,就增加2*(n-1)个回旋镖
应该不是最优解

```
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int num=0;
        int dis=0;
        unordered_map<int,int> n;
        for(int i=0;i<points.size();++i){
            n.clear();
            for(int j=0;j<points.size();++j){
                if(i!=j){
                    dis=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                    n[dis]++;//同长度线段计数
                    if (n[dis]>1)
                        num+=2*(n[dis]-1);//一次加入等长线段,增加2*(n-1)个回旋镖
                }
            }
        }
        return num;
    }
};
```
