![image.png](https://pic.leetcode-cn.com/bfbf6f6ed96d22f05b0add7baa38b183ef77aefb552a899b116d815ec17ec18a-image.png)

### 解题思路
套dfs模板，设计visited数组防止重复访问，
注意开始需要判断起始点是否符合条件

### 代码

```cpp
class Solution {
public:
    //初始化x,y方向数组
    int dirX[4]={0,0,1,-1};
    int dirY[4]={1,-1,0,0};
    int res=0;
    int movingCount(int m, int n, int k) {
        //初始化visited数组
        vector<vector<int>> visited(m,vector<int>(n,0));
        //判断[0,0]是否符合条件，因为后续dfs直接是从子节点遍历了
        if(isValid(m,n,0,0,k)) res++;
        dfs(m,n,0,0,k,visited);
        return res;
    }
    bool isValid(int m,int n,int x,int y,int k){
        //边界判断加上位数判断
        if(x<=m-1&&x>=0&&y<=n-1&&y>=0){
            int sum=x/10+x%10+y/10+y%10;
            if(sum<=k) return true;
        }
        return false;
    }
    void dfs(int& m,int& n,int x,int y,int& k,vector<vector<int>>& v){
        //套dfs模板
        v[x][y]=1;
        for(int i=0;i<4;i++){
            int newPosX=x+dirX[i];
            int newPosY=y+dirY[i];
            if(isValid(m,n,newPosX,newPosY,k)) {
                if(v[newPosX][newPosY]==1) continue;
                res++;
                dfs(m,n,newPosX,newPosY,k,v);
            }

        }
    }
};
```