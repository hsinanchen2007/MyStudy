class Solution {
public:
    string getPermutation(int n, int k) {
        getfac(10);
        return reverseKangtuo(n, k);
    }
    void getfac(int n){
        fac.push_back(1);
        for(int i = 1; i <= n; ++i){
            fac.push_back(fac[fac.size() - 1] * i);
        }
    }
    string reverseKangtuo(int n, int k){
        k--;
        int t;
        int vs[20] = {0};
        string rs;
        for(int i = 0; i < n; i++){
            t = k / fac[n - 1 - i] + 1;
            k = k % fac[n - 1 - i];
            for(int j = 1; j <= n; ++j){
                if(!vs[j]){
                    t--;
                    if(t == 0){
                        rs+=(j + '0');
                        vs[j] = 1;
                        break;
                    }
                }
            }
        }
        return rs;
    }

    vector<int> fac;
    //321
    //2 * 2! + 1 * 1! + c * 0! 
};