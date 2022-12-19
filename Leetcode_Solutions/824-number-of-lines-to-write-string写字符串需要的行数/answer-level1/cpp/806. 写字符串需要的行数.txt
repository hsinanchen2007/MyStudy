```
vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int>res(2,0);
        res[0] = 1;
        for(int i=0;i<S.length();i++){
            res[1] += widths[S[i]-'a'];
            if(res[1] > 100){
                res[0]++;
                res[1] = widths[S[i]-'a'];
            }
        }
        return res;
    }
```
