离散化后变为中等难度的题
离散化需要注意边界问题，即是否可以在边界外活动。
```
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        vector<int> v,v1;
        set<int> s,s1;
        for(auto a:blocked){
            if(!s.count(a[0])){
                v.push_back(a[0]);
                s.insert(a[0]);
            }
            if(!s1.count(a[1])){
                v1.push_back(a[1]);
                s1.insert(a[1]);
            }
        }
        if(!s.count(source[0])){
            v.push_back(source[0]);
            s.insert(source[0]);
        }
        if(!s1.count(source[1])){
            v1.push_back(source[1]);
            s1.insert(source[1]);
        }
        if(!s.count(target[0])){
            v.push_back(target[0]);
            s.insert(target[0]);
        }
        if(!s1.count(target[1])){
            v1.push_back(target[1]);
            s1.insert(target[1]);
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        map<int,int> m,m1;
        for(int i=0;i<v.size();++i){
            m[v[i]]=i;
        }
        for(int i=0;i<v1.size();++i){
            m1[v1[i]]=i;
        }
        for(int i=0;i<blocked.size();++i){
            blocked[i][0]=m[blocked[i][0]];
            blocked[i][1]=m1[blocked[i][1]];
        }
        source[0]=m[source[0]];
        source[1]=m1[source[1]];
        target[0]=m[target[0]];
        target[1]=m1[target[1]];
        int x1,x2,y1,y2;
        x1=*v.begin()==0?0:-1;
        x2=*v.rbegin()==(1000000-1)?m[*v.rbegin()]:m[*v.rbegin()]+1;
        y1=*v1.begin()==0?0:-1;
        y2=*v1.rbegin()==(1000000-1)?m1[*v1.rbegin()]:m1[*v1.rbegin()]+1;
        return lalala(blocked,source,target,x1,x2,y1,y2);
        
    }
    bool lalala(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target,int x1,int x2,int y1,int y2) {
        
        set<pair<int,int>> s;
        set<pair<int,int>> log;
        queue<pair<int,int>> q;
        for(auto a:blocked){
            s.insert({a[0],a[1]});
        }
        q.push({source[0],source[1]});
        while(!q.empty()){
            int size=q.size();
            pair<int,int> temp;
            for(int i=0;i<size;++i){
                temp=q.front();
                int first=temp.first;
                int second=temp.second;
                q.pop();
                if(first<x1||first>x2||second<y1||second>y2){
                    continue;
                }
                if(!s.count({first,second})&&!log.count({first,second})){
                    log.insert({first,second});
                    q.push({first+1,second});
                    q.push({first-1,second});
                    q.push({first,second+1});
                    q.push({first,second-1});
                }
            }
        }
        return log.count({target[0],target[1]});
    }
};
```
