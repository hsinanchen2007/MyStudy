```
class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        map<string,string> m;//先大的，后小的
        vector<string> ans;
        for(int i=0;i<synonyms.size();++i){
            string temp=synonyms[i];
            string second=temp.substr(1,temp.find(',')-1);
            string first=temp.substr(temp.find(',')+1,temp.size()-1-temp.find(',')-1);
            if(second<first){
                swap(first,second);
            }
            while(m.count(second)){
                if(m[second]>first){
                    second=m[second];
                }
                else if(m[second]==first){
                    break;
                }
                else if(m[second]<first){
                    if(m.count(first)){
                        string lfx=first;
                        first=m[second];
                        second=lfx;
                    }
                    else{
                        m[first]=m[second];
                        m[second]=first;
                        break;
                    }
                }
            }    
            if(!m.count(second)){
                m[second]=first;   
            }
        }
        map<string,int> mnum;
        for(int i=0;i<names.size();++i){
            string temp=names[i];
            string s=temp.substr(0,temp.find('('));
            int num=stoi(temp.substr(s.size()+1,temp.size()-1-s.size()-1));
            while(m.count(s)){
                s=m[s];
            }
            mnum[s]+=num;
        }
        for(int i=0;i<names.size();++i){
            string temp=names[i];
            string s=temp.substr(0,temp.find('('));
            if(!m.count(s)){
                ans.push_back(s+"("+to_string(mnum[s])+")");
            }
        }
        return ans;
    }
};
```
