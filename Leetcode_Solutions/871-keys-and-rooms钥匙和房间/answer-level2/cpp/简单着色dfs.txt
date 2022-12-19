class Solution {
int N;
vector<vector<int>> rooms;
private:
    void dfs(int x,vector<int>& visit)
    {
        visit[x] = 1;
        int k = rooms[x].size();
        for(int i=0;i<k;i++)
        {
            if(visit[rooms[x][i]]==0)
            dfs(rooms[x][i],visit);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& _rooms) 
    {   
        rooms = _rooms;
        N = _rooms.size();
        if(N==0)return true;//没有房间就算可以进入所有房间吧
        vector<int> visit(N,0);
        dfs(0,visit);
        bool res = 1;
        for(int i=0;i<N;i++)
        {
            if(visit[i]==0)res=0;
        }
        return res;
    }
};