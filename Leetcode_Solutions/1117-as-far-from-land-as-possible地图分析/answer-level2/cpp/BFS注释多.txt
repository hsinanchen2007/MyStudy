#1、思路：
BFS搜索，陆地填海，使用queue
一次遍历，找出所有陆地，初始化队列，然后根据这个队列中的陆地，把附近的海洋找出来（和此一层陆地相接的海洋），填成陆地，添加到陆地队列，构成队列第二层陆地，（添加的同时把原来的陆地删除），然后再根据第二层陆地，填第3层海...
#2、code
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {       
        int n=grid.size();      //大小                   
        queue<pair<int,int>> queList;  //陆地队列，把座标添加到队列
        
        for(int i=0;i<n;i++)  //第一次遍历，如果是1，就添加到陆地队列
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                queList.push({i,j});
            }
        }

        if(queList.size()==0 || queList.size()==n*n)  return -1;//全是陆地或者全是海洋返回-1       
           
        int count;  //每一层的更新，
        int res=0;  //统计最后最远的结果
        while(!queList.empty())  //陆地队列不为空，
        {
           
            int  queTemSize=queList.size();  //当前一层的陆地个数，
            bool flag=false;  // 判断新一层有没有新的陆地生成
            int direct[5]={0,1,0,-1,0};  // 方向
            while(queTemSize--)  // 一层判断完事
            {
                 auto Val=queList.front(); //变量类型 pair<int,int>
                 queList.pop();  //首元素出队列
                for(int i=0;i<4;i++)  //四个方向
                {
                    int nx=Val.first+direct[i];  //上下左右四周的下标 
                    int ny=Val.second+direct[i+1];
                    if(nx<0 ||ny<0||nx>=n||ny>=n||grid[nx][ny]==1){ //不符合就跳过
                        continue; 
                    }                                                                           
                    queList.push({nx,ny}); //四个方向有一个加一个
                    grid[nx][ny]=1;   //填海
                      flag=true;       //整个一层while循环，有一个就够      
                }                               
            }
            if(flag)  //加一层
            res++;         
        }
        return res;
    }
};