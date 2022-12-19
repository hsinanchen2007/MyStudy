### 解题思路
执行用时击败了84.56%，感觉效率还可以。
题目的限制是只会出现一条多余的边，那就一条边一条边的加入，直到加入一个边的时候出现了环。
怎么判断环呢？我采用并查集！
只需要判断新加入的边的两个节点是否拥有同一个父亲，即可知道是否构成了环！

### 代码

```cpp
class Solution {
public:
    //static const int MAXV=1010;
    int father[1010];
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //从头开始插入，一旦碰到插入的边使得原图出现了环，就输出它
        //用并查集找father
        for(int i=0; i<1010; i++) father[i]=i;
        vector<int> re;
        int root=edges[0][0];
        for (int i=0; i<edges.size(); i++){
            int faU=findFather(edges[i][0]-1);
            int faV=findFather(edges[i][1]-1);
            if ( faU != faV){
                if (faU==root) father[faV]=faU;
                else father[faU]=faV;
            }
            else{
                return edges[i];
            }
        }
        return re;

    }
    int findFather(int x){
        int a=x;
        while(x!=father[x]) x=father[x];
        while(a!=father[a]){
            int z=a;
            a=father[a];
            father[z]=x;
        }
        return x;
    }
};
```