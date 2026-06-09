```
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> tmp;
        map<string,int> d;
        vector<string> res;
        int p[101];
        for(int i=0;i<=100;i++)
            p[i]=0;
        for(int i=0;i<friends[id].size();i++){
            tmp.push(friends[id][i]);
            p[friends[id][i]]++;
        }
        p[id]++;
        for(int i=1;i<level;i++){
            int size=tmp.size();
            for(int j=0;j<size;j++){
                int k=tmp.front();
                tmp.pop();
                for(int s=0;s<friends[k].size();s++){
                    if(p[friends[k][s]]==0)
                    {tmp.push(friends[k][s]);p[friends[k][s]]++;}
                 }
            }
        }
        for(int i=0;i<=100;i++)
            p[i]=0;
        while(!tmp.empty()){
            p[tmp.front()]++;
            tmp.pop();
        }
        for(int j=0;j<=100;j++){
            if(p[j]!=0){
                for(int i=0;i<watchedVideos[j].size();i++){
                    d[watchedVideos[j][i]]++;
                }
            }
            
        }
        map<string,int>::iterator its;
        for(its=d.begin();its!=d.end();its++){
            res.push_back((*its).first);
        }
        sort(res.begin(),res.end(),[&](string &a,string &b)->bool{
            if(d[a]<d[b]) return true;
            else if(d[a]>d[b]) return false;
            else
                return a<b;
        });
        return res;
    }
};
```

