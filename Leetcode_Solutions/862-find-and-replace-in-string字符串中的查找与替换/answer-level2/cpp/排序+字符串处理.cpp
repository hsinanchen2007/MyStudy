对indexes, sources 和 targets 按照升序排列，然后再遍历一次字符串S，到indexes[id]==i的位置判定sources[id]是否是S中连续的一段，若是，则替换。
```
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        pair<int,pair<string,string> > p[indexes.size()];
        for(int i=0;i<indexes.size();i++) p[i] = {indexes[i],{sources[i],targets[i]}};
        sort(p,p+indexes.size());
        for(int i=0;i<indexes.size();i++){
            indexes[i] = p[i].first;
            sources[i] = p[i].second.first;
            targets[i] = p[i].second.second;
        }
        string ans;
        int id=0;
        for(int i=0;i<S.size();){
            if(id<indexes.size() && indexes[id]==i){
                if(S.substr(indexes[id],sources[id].size()) == sources[id]){
                    ans+=targets[id];
                    i+=sources[id].size();
                }else{
                    ans+=S[i++];
                }
                id++;
            }else{
                ans+=S[i++];
            }
        }
        return ans;
    }
};

```
