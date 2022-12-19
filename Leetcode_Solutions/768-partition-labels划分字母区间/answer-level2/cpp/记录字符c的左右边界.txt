```
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int> mfirst,msecond;
        for(int i=0;i<S.size();++i){
            if(!mfirst.count(S[i])){
                mfirst[S[i]]=i;
            }
            else{
                mfirst[S[i]]=min(mfirst[S[i]],i);
            }
            if(!msecond.count(S[i])){
                msecond[S[i]]=i;
            }
            else{
                msecond[S[i]]=max(msecond[S[i]],i);
            }
        }
        vector<char> v(S.size(),' ');
        for(auto a:mfirst ){
            v[a.second]=a.first;
        }
        for(auto a:msecond){
            if(v[a.second]!=' '){
                v[a.second]=' ';
            }
            else{
                v[a.second]=a.first;
            }
        }
        set<char> s;
        vector<int> ans;
        int now=0;
        int first=-1;
        for(int i=0;i<v.size();++i){
            if(v[i]!=' '){
                if(!s.count(v[i])){
                    ++now;
                    first=now==1?i:first;
                    s.insert(v[i]);
                }
                else{
                    --now;
                }
            }
            if(now==0){
                if(first==-1){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(i-first+1);
                }
                first=-1;
            }
        }
        return ans;

    }
};
```
