```c++
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        
        map<char,int> w;
        for (int i=0;i<widths.size();i++){
            w[char('a'+i)]=widths[i];
        }
        int total=0,line=1;
        int i=0;
        while (i<S.size()){
            total+=w[S[i]];
            if (total>100){
                line+=1;
                total=w[S[i]];
            }
            i++;
        }
        vector<int> ans={line,total};
        return ans;
    }
};
```
