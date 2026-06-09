### 解题思路
一开始找最大值的时候忘了max的写法，自己写了一个双重for循环，用内存换时间。一提交发现内存用得有点多，去找题解交上去内存也没有优化多少，反而时间变慢了。。。。自己想不出什么好的内存优化方法，有无高手指点一下？
### 代码

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
   int zy[grid.size()],sx[grid.size()];
    int zt[grid.size()],st;
    int ans=0;
    for(int i=0;i<=grid.size();++i){
        int h=i-1;
        if (i>0)
            zy[h]=(*max_element(zt, zt +grid.size())) ;
        if(i==grid.size()) break;

        for(int j=0;j<grid.size();++j){
            if(i==0)
                sx[j]=grid[i][j];
            if(sx[j]<grid[i][j]) sx[j]=grid[i][j];
            zt[j]=grid[i][j];
        }
    }
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid.size();j++){
            ans+=min(zy[i],sx[j])-grid[i][j];
//            grid[i][j]=min(zy[i],sx[j]);
        }

//    for(int i=0;i<grid.size();i++){
//        for(int j=0;j<grid.size();j++){
//            cout<<grid[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    return ans;


    }
};
```
![image.png](https://pic.leetcode-cn.com/57e625f61429db3a819b58a4d004168250e5e64800ece223d55abf112d961c04-image.png)

```c++

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        vector<int> row_max(R, 0);
        vector<int> col_max(C, 0);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return res;
    }
};

作者：da-li-wang
链接：https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/solution/c-jian-dan-ti-jie-by-da-li-wang-17/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```
![image.png](https://pic.leetcode-cn.com/5d5c34ec24fdf5d9e53b286f7eda0404e17e13db8d9db4fdd66a56051b8221c1-image.png)