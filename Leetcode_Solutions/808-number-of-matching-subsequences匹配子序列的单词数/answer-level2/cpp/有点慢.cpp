```
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<int,vector<int>> log;
        vector<int> vtemp(26,-1);
        for(int i=S.size()-1;i>=0;--i){
            vtemp[S[i]-'a']=i;
            log[i-1]=vtemp;
        }
        
        
        int ans=0;
        for(const auto& w:words){
            if(lalala(log,w,0,-1)){
                ++ans;
            }
        }
        return ans;
    }

    bool lalala(map<int,vector<int>>& log,const string& s,int sp,int pos){
        if(sp==s.size()){
            return true;
        }
        if(pos==(int)log.size()-1){
            return false;
        }

        int last=log[pos][s[sp]-'a'];
        if(last!=-1&&lalala(log,s,sp+1,last)){
            return true;
        }
        for(int i=pos;i<(int)s.size()-1;++i){
            
            int temp=log[i][s[sp]-'a'];
            if(temp!=-1&&last!=temp){
                if(lalala(log,s,sp+1,temp)){
                    return true;
                }
                last=temp;
            }
            
        }
        return false;
        
    }


};
```
