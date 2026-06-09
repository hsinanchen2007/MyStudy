class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        map<int,int> m;
        int ans=1;
        for(int i=0;i<M.size();++i){
            if(m[i]==0){
                bfs(M,m,ans,i);
                ++ans;
            }
        }
        return ans-1;
    }

    void bfs(const vector<vector<int>>& M,map<int,int>& m,int ans,int pos){
        for(int i=0;i<M.size();++i){
            if(M[pos][i]==1&&m[i]==0){
                m[i]=ans;
                bfs(M,m,ans,i);
            }
        }
    }
};