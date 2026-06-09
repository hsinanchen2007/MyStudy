```
class Solution {//计算每块陆地相邻有多少陆地，多一陆地周长+1；

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum =0 ;
        int line =0;
        int n = grid[0].size();
        for (int i =0 ; i< grid.size() ; i++){
            for (int j = 0 ; j< n ;j++){
                if (grid[i][j] !=0)
                {
                    //左边
                    if (j >0 && grid[i][j-1]==0){
                        sum++;
                    }
                    if (j==0){
                        sum++;
                    }
                    //右边
                    if (j<n-1 && grid[i][j+1]==0){
                        sum++;
                    }
                    if (j== n-1){
                        sum++;
                    }
                    //上面
                    if (i ==0){
                        sum++;
                    }
                    if(i !=0 && grid[i-1][j]==0 ){
                        sum++;
                    }
                    //下面
                    if (i == grid.size()-1){
                        sum++;
                    }
                    if (i != grid.size()-1 && grid[i+1][j]==0){
                        sum++;
                    }
                }
            }
            
            

        }
        return sum;
        
    }
};
```
![image.png](https://pic.leetcode-cn.com/450aa92558bfa4d7ce0bae9abbe906e0f12c28257a2dccbdf2557f9d5223ab87-image.png)


我这个判断时间太长了。。。