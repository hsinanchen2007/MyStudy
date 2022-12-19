```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(),0);
        int deep = 0;
        for(int i = 0; i < seq.size(); ++i){
            if(seq[i] == '('){
                res[i] = (deep++)%2;
            }
            else{
                res[i] = (--deep)%2;
            }
        }
        return res;
    }
};
```
