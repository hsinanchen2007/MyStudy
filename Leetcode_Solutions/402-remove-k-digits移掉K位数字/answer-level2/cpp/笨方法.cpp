```
class Solution {
public:
    string removeKdigits(string num, int k) {
        int count=num.size()-k;
        map<int,vector<int>> bp;
        vector<int> temp(10,-1);
        for(int i=num.size()-1;i>=0;--i){
            temp[num[i]-'0']=i;
            bp[i-1]=temp;
        }
        string ans="";
        int pos=-1;
        while(count>0){
            for(int i=0;i<10;++i){
                if(bp[pos][i]!=-1&&(num.size()-bp[pos][i])>=count){
                    ans+=('0'+i);
                    pos=bp[pos][i];
                    --count;
                    break;
                }
            }
        }
        pos=0;
        while(pos<ans.size()&&ans[pos]=='0'){
            ++pos;
        }
        return pos==ans.size()?"0":ans.substr(pos);
    }
};
```
