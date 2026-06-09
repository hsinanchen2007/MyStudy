### 解题思路
如标题所示，将陆地一轮又一轮地扩大，直到覆盖完全，计算扩大了多少轮，输出轮数即可，扩大的地方进行赋值，并根据具体轮数做区分，看我的例子就明白了
![截屏2020-03-29 上午9.21.20.png](https://pic.leetcode-cn.com/da2a0bea26cb8e72d2292cbdcd34332ddb917985076519075d85043c0e6b8e24-%E6%88%AA%E5%B1%8F2020-03-29%20%E4%B8%8A%E5%8D%889.21.20.png)
（这是初始状况）
![截屏2020-03-29 上午9.27.00.png](https://pic.leetcode-cn.com/ca6dac699384ab2f72fac9cf0ae3b174b22e17e840197f38757be892cda5c84b-%E6%88%AA%E5%B1%8F2020-03-29%20%E4%B8%8A%E5%8D%889.27.00.png)
（进行第1轮操作,对值为1的陆地判断它上下左右的四个点，如果值为0就进行“长大”，赋值为2）（同时还记录剩余的为0的点数，直到地图上没有0）
![截屏2020-03-29 上午9.29.27.png](https://pic.leetcode-cn.com/609e0a86b1dd8bd78a9077eedc9682b7b63f25d985196c99d9d879712ee660b9-%E6%88%AA%E5%B1%8F2020-03-29%20%E4%B8%8A%E5%8D%889.29.27.png)
（第2轮操作，对值为2的陆地做“长大”，同上，并赋值为3）
![截屏2020-03-29 上午9.30.53.png](https://pic.leetcode-cn.com/3590957781d6159da8589202ce34b9ca146a5a401a7448ad9f5b1e2c02e7d1c1-%E6%88%AA%E5%B1%8F2020-03-29%20%E4%B8%8A%E5%8D%889.30.53.png)
（第3轮操作，地图填满了，结束，跳出）（输出轮数3，就是答案,坐标（4，4）值为4的那个点就是要找的最优海域）

如果有帮到你，就点个赞吧^_^


### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        int count_land = 0;
        int count_turn = 0;
        int count_last_space;
        for(int i=0;i<N;i++){
            for(int j =0;j<N;j++){
                if(grid[i][j]==1){
                    count_land++;
                }
            }
        }
        if(count_land==N*N||count_land==0){
            return -1;
        }
        count_last_space = N*N-count_land;
        while(count_last_space!=0){
            count_turn++;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(grid[i][j]==count_turn){
                        if(i>0&&grid[i-1][j]==0){
                            grid[i-1][j]=count_turn+1;
                            count_last_space--;
                        }
                        if(i<N-1&&grid[i+1][j]==0){
                            grid[i+1][j]=count_turn+1;
                            count_last_space--;
                        }
                        if(j>0&&grid[i][j-1]==0){
                            grid[i][j-1]=count_turn+1;
                            count_last_space--;
                        }
                        if(j<N-1&&grid[i][j+1]==0){
                            grid[i][j+1]=count_turn+1;
                            count_last_space--;
                        }
                    }
                }
            }
        }
        return count_turn;
    }
};//题意是对每个海洋区域，计算到每个陆地的距离并取最短的，在这些最短的区域里找最大的那个；只有陆地或海洋的情况单独拿出来看
```