class Solution {//广度优先搜索
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int curlevel=0;//当前层
        queue<int> q;
        q.push(id);
        set<int> visited;//记录访问过的点
        visited.insert(id);
        int last=id;//记录每一层遍历结束的那个点
        while(curlevel<level){
            int tmp=q.front();q.pop();
            //cout<<tmp<<endl;
            for(int i=0;i<friends[tmp].size();i++){//与这个点邻接的所有点
                if(visited.find(friends[tmp][i])==visited.end()){//如果该点没有被访问过
                    q.push(friends[tmp][i]);
                    visited.insert(friends[tmp][i]);
                }
            }
            if(last==tmp){//每一层遍历结束了，当前层数加1.
                ++curlevel;
                last=q.back();
            }
        }
        vector<string> ans;
        map<string,int> mp;
        vector<pair<string,int>> vec;
        while(!q.empty()){
            int tmp=q.front();q.pop();
            //cout<<tmp<<endl;
            for(int i=0;i<watchedVideos[tmp].size();i++){
                mp[watchedVideos[tmp][i]]++;
            }
        }
        for(map<string,int>::iterator iter=mp.begin();iter!=mp.end();iter++){
            vec.push_back(make_pair(iter->first,iter->second));
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }

private:
    static bool cmp(pair<string,int>& A,pair<string,int>& B){
        if(A.second!=B.second) return A.second<B.second;
        else return A.first<B.first;
    }
};