```
class Solution {
public:
    string reorganizeString(string S) {
        int max_num=0;
        char max_c;
        vector<int> v(26,0);
        for(auto a:S){
            ++v[a-'a'];
        }
        for(int i=0;i<26;++i){
            if(v[i]>max_num){
                max_num=v[i];
                max_c='a'+i;
            }
        }
        if((S.size()-max_num)<max_num-1)return "";
        vector<vector<char>> vc(max_num);
        int pos=0;
        for(int i=0;i<26;++i){
            if(('a'+i)==max_c)continue;
            while(v[i]>0){
                vc[pos].push_back('a'+i);
                --v[i];
                pos=(pos+1)%max_num;
            }
        }
        string ans="";
        for(int i=0;i<max_num;++i){
            ans+=max_c;
            for(auto a:vc[i]){
                ans+=a;
            }
        } 
        return ans;
    }
};
```
