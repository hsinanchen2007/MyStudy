### 解题思路
思路基本写在代码里了，附上提交测评结果，哈哈~~

![微信截图_20200318114738.png](https://pic.leetcode-cn.com/1c1fc4274019a7a5ac657554156f3bd64fa3be30c7fb6ab055cbb71a1deef3bd-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200318114738.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));//别写成vector<vector<int>> res;
        vector<vector<bool>> st(n,vector<bool>(n,false));   //判断是否已经走过
        int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};  //定义四个方向
        int x = 0,y = 0,d = 0;//x,y为初始横纵坐标，d用来控制四个方向（右->下->左->上->右->....）
        for(int i = 1;i <= n*n;i++){
            res[x][y] = i;
            st[x][y] = true;

            int tx = x + dx[d];
            int ty = y + dy[d];

            //tx,ty不符合约束的话，重新计算下标
            if(tx < 0 || tx >= n || ty < 0 || ty >= n || st[tx][ty]){
                d = (d + 1) % 4;
                tx = x + dx[d],ty = y + dy[d];
            }
            //更新此时的横纵坐标
            x = tx,y = ty;
        }
        return res;
    }
};
```