自己可以在纸上比划一下，会发现规律，先按当前方向走，不行就按右上左下的方向走，初始位置一定是（0,0），方向一定是右，加上相应的剪枝
剪枝是避免了得到结果后免去了所有不合法的多余选择，直接返回
因为路径的唯一的，所以只要的有效选择，就是最终选择
```
class Solution {
public:
    //先按当前，不行就右下左上
    int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//四个方向
    int M;
    int N;
    vector<int> ans;
    vector<vector<bool>> visited;
    bool vaild(int x,int y){
        return x>=0 && x<M && y>=0 && y<N;
    }
    //二维遍历回溯框架，d1,d2保存的是现在的方向
    void f(vector<vector<int>>& matrix,int startx,int starty,int d1,int d2){
        visited[startx][starty] = true;
        ans.push_back(matrix[startx][starty]);
        //试着按原方向走
        int newx = startx + d1;
        int newy = starty + d2;
        if(vaild(newx,newy) && !visited[newx][newy] ){
            f(matrix,newx,newy,d1,d2);
            return;
        }
        //不行就按右下左上
        for(int i=0;i<4;i++){
            newx = startx + d[i][0];
            newy = starty + d[i][1];
            if(!vaild(newx,newy) || visited[newx][newy] ) continue;
            f(matrix,newx,newy,d[i][0],d[i][1]);
            return ;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        M = matrix.size();
        if(M == 0 )
            return ans;
        N = matrix[0].size();
        visited =  vector<vector<bool>>(M,vector<bool>(N,false));
        f(matrix,0,0,0,1);//初始位置一定是（0,0），方向一定是右
        return ans;
    }
};
```
