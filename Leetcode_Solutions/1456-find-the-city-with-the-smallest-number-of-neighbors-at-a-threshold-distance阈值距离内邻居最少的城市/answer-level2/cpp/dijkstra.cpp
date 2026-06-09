class Solution {
public:
     
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int arr[n][n];
        memset(arr,0x3f,sizeof(arr));
        for(int i=0;i<edges.size();i++)//无向图双向拷贝
        {
            arr[edges[i][0]][edges[i][1]]=edges[i][2];
            arr[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        vector<vector<int>> result_all_shortest;
        vector<bool>visit;
        vector<int>path;
        int pos =-1,MinCount =INT_MAX;

        for(int index = 0;index < n; ++index)//求n个点最短路径
        { 
           visit.clear();   path.clear();        
            visit.resize(n,false);
            path.resize(n,INT_MAX);
            for(int i =0;i<n;i++)path[i]=arr[index][i]; 
            path[index]=0;visit[index]=true;

            for(int check=1;check<n;check++)//每个点到其他n-1个点的最短路径，添加n-1次
            {
                int Min = INT_MAX;
                int flag = -1;
                for(int i=0;i<n;i++)
                {
                    if(!visit[i] && path[i]<Min)
                    {
                        Min =path[i];
                        flag =i;
                    }
                }
                visit[flag]=true;
                for(int i= 0;i<n;i++)
                {
                    if(!visit[i] && path[i]>arr[flag][i]+path[flag])
                        path[i]=arr[flag][i]+path[flag];
                }
            }    
            //result_all_shortest.push_back(path);
            int count=0;
            for(int j=0;j<n;j++)
            {                
                if(path[j]<=distanceThreshold)count++;
            }
            if(count<=MinCount)
            {
                 MinCount= count;
                 pos =index;    
            } 
        }              
        return pos;
    }   
};