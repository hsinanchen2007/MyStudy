对于不同的团队之间视为一个整体建立拓扑结构，团队内部的任务再建立拓扑结构
```
struct node_info{
    int indegree;
    vector<int> point_to;
};
struct inner_top{
    bool is_one;
    map<int,int> without_indegree;
    map<int, node_info> mp;
};
class Solution {
public:
    //双层拓扑排序
    int finished=0;
    vector<int> fail;
    vector<int> res;
    queue<int> bzdsmmzl;
    int max_num=30000;
    inner_top* group_top[30000];
    vector<int> group_point[30000];
    int group_in_degree[30000];
    inner_top *innertop;
    node_info *nodeinfo;
    map<int,int> father;
    bool process_group_i(int i){
        //内部拓扑能不能实现拓扑排序
        innertop=group_top[i];
        for(int to:group_point[i]){
            group_in_degree[to]--;
            if(group_in_degree[to]==0)bzdsmmzl.push(to);
        }
        if(innertop->is_one){
            finished++;
            res.push_back(father[i]);
            cout<<i<<" ";
            return true;
        }
        queue<int> innerbzd;
        map<int,int>::iterator it=innertop->without_indegree.begin();
        for(it;it!=innertop->without_indegree.end();it++){
            innerbzd.push(it->first);
        }
        int innfinished=0;
        while(!innerbzd.empty()){
            int now=innerbzd.front();innerbzd.pop();
            innfinished++;res.push_back(now);
            for(int innerto:innertop->mp[now].point_to){
                innertop->mp[innerto].indegree--;
                if(innertop->mp[innerto].indegree==0)innerbzd.push(innerto);
            }
        }
        if(innfinished!=innertop->mp.size())return false;
        finished+=innfinished;
        return true;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        max_num--;
        memset(group_in_degree,-1,sizeof(group_in_degree));
        for(int i=0;i<group.size();i++){
            innertop=new inner_top;
            if(group[i]==-1){
                group_in_degree[max_num]=0;
                group[i]=max_num;
                father[max_num]=i;
                innertop->is_one=true;
                group_top[max_num]=innertop;
                max_num--;
            }
            else{
                nodeinfo=new node_info;
                nodeinfo->indegree=0;
                if(group_in_degree[group[i]]==-1){
                    group_in_degree[group[i]]=0;
                    innertop->without_indegree[i]=0;
                    innertop->mp[i]=*nodeinfo;
                    innertop->is_one=false;
                    group_top[group[i]]=innertop;
                }
                else{
                    group_top[group[i]]->mp[i]=*nodeinfo;
                    group_top[group[i]]->without_indegree[i]=0;
                }
            }
        }
        for(int i=0;i<group.size();i++){
            for(int nei:beforeItems[i]){
                if(group[i]==group[nei]){
                   group_top[group[i]]->without_indegree.erase(i);
                   group_top[group[i]]->mp[nei].point_to.push_back(i);
                   group_top[group[i]]->mp[i].indegree++;
                }
                else{
                    group_in_degree[group[i]]++;
                    group_point[group[nei]].push_back(group[i]);
                }
            }
        }
        for(int i=0;i<30000;i++){
            if(group_in_degree[i]==0){
                bzdsmmzl.push(i);
            }
        }
        while(!bzdsmmzl.empty()){
            if(!process_group_i(bzdsmmzl.front()))return fail;
            bzdsmmzl.pop();
        }
        if(finished==group.size())return res;
        return fail;
    }
};
```
