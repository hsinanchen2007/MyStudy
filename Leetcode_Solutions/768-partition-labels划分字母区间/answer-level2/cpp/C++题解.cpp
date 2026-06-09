```
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<vector<int>> dict(26,vector<int>(2,-1));
        int len = S.length();
        for(int i=0;i<len;++i){
            int idx = S[i]-'a';
            if(dict[idx][0] == -1) dict[idx][0] = dict[idx][1] = i;
            else dict[idx][1] = i;
        }
        sort(dict.begin(),dict.end(),cmp);
        int start = -1,end = -1,i = 0;
        while(i<26){
            if(dict[i][0] != -1){
                if(start == -1){
                    start = dict[i][0];
                    end = dict[i][1];
                    i++;
                }else{
                    while(i<26 && end>dict[i][0]) end = max(end,dict[i][1]),i++;
                    ans.push_back(end-start+1);
                    start = end = -1;
                }
            }else i++;
        }
        if(start != -1) ans.push_back(end-start+1);
        return ans;
    }
};
```