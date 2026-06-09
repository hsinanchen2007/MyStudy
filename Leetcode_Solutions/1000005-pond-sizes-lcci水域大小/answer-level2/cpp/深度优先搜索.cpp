### 解题思路
深度优先搜索的经典题目，设置两个数组用来遍历特定节点的四周八个点会简洁一点。

### 代码

```cpp
class Solution {
public: 
    int x[8]={0,1,1,1,0,-1,-1,-1};
    int y[8]={1,1,0,-1,-1,-1,0,1};
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[i].size();j++){
                //这里或许先判断i，j处是否为0，不为0则跳过比较好，
                //但执行用时还真是不准确，优化以后更慢了，估计是系统原因而不是算法
                int t=dfs(land,i,j);
                if(t!=0){
                    res.push_back(t);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    int dfs(vector<vector<int>>& land,int i,int j){
        if(i<0||i>=land.size()||j<0||j>=land[i].size()){
            return 0;
        }
        if(land[i][j]!=0){
            return 0;
        }else{
            int res=0;
            land[i][j]=INT_MAX; //不更改会陷入死循环
            for(int a=0;a<8;a++){
                res+=dfs(land,i+x[a],j+y[a]);
            }
            return res+1;
        }
        
    }
};
```