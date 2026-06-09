```c++
class Solution {
public:
    void quickpower(const vector<int> &sub, int power, vector<int> &res){
        if(power == 0){
            res[0] = 1; res[1] = 0; res[2] = 0; res[3] = 1;
            return;
        }
        if(power == 1){
            res[0] = sub[0]; res[1] = sub[1]; res[2] = sub[2]; res[3] = sub[3];
            return;
        }
        vector<int> half(4);
        quickpower(sub, power/2, half);
        res[0] = half[0] * half[0] + half[1] * half[2];
        res[1] = half[0] * half[1] + half[1] * half[3];
        res[2] = half[2] * half[0] + half[3] * half[2];
        res[3] = half[2] * half[1] + half[3] * half[3];
        if(power % 2 == 1){
            vector<int> tmp(4);
            tmp[0] = res[0] * sub[0] + res[1] * sub[2];
            tmp[1] = res[0] * sub[1] + res[1] * sub[3];
            tmp[2] = res[2] * sub[0] + res[3] * sub[2];
            tmp[3] = res[2] * sub[1] + res[3] * sub[3];
            res[0] = tmp[0];res[1] = tmp[1];res[2] = tmp[2];res[3] = tmp[3];
        }
        return;
    }
    int fib(int N) {
        if(N <= 1){
            return N;
        }
        vector<int> sub(4, 0);
        sub[0] = sub[1] = sub[2] = 1;
        vector<int> res(4);
        quickpower(sub, N, res);
        sub[0] = 0; sub[1] = 0;sub[2] = 1;sub[3] = 0;
        vector<int> tmp(4);
        tmp[0] = res[0] * sub[0] + res[1] * sub[2];
        tmp[1] = res[0] * sub[1] + res[1] * sub[3];
        tmp[2] = res[2] * sub[0] + res[3] * sub[2];
        tmp[3] = res[2] * sub[1] + res[3] * sub[3];
        return tmp[0];
    }
};
```
