具体的看代码吧，很好理解的。
```
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> ret_tp;
    int k;
    int n;
    int k_tp;
    int n_tp;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        this -> k = k;
        this -> n = n;
        this -> k_tp = 0;
        this -> n_tp = 0;
        helper(1);
        return ret;
    }
    
    void helper(int num){
        if(k_tp > k || n_tp > n)
            return;
        
        if(k_tp == k && n_tp == n){
            ret.push_back(ret_tp);
            return;
        }
        
        for(int i=num;i<=9;i++){
            if(n-n_tp < i)
                return ;
            
            n_tp += i;
            k_tp++;
            ret_tp.push_back(i);
            
            helper(i+1);

            n_tp -= i;
            k_tp--;
            ret_tp.pop_back();    
        }
        
    }
};
```
