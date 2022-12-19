没有想到还能这么简单的解法过了。。。
```
class Solution {
public:
    string crackSafe(int n, int k) {
        int count = pow(k,n);
        string res(n,'0');
        set<string> visit;
        
        /*intial*/
        visit.insert(res);
        for(int i = 0;i < count; ++i){
            string curr = res.substr(res.size()-n+1,n-1);
            for(int j = k-1; j >= 0; --j){
                curr.push_back('0' + j);
                if(!visit.count(curr)){
                    visit.insert(curr);
                    res.push_back('0'+j);
                    break;
                }
                curr.pop_back();
            }
        }  
        
        return res;
    }
};
```