    class Solution {
    public:
        void backtrace(vector<int>& ret,int& cur,int& n,int& N,int& K){
            if(n == N){ret.push_back(cur);return;}
            int tail = cur%10;
            if(tail + K <= 9){
                cur *= 10;
                cur += tail+K;
                backtrace(ret,cur,++n,N,K);
                --n;
                cur /= 10;
            }
            if(tail - K >= 0){
                cur *= 10;
                cur += tail-K;
                backtrace(ret,cur,++n,N,K);
                --n;
                cur /= 10;
            }
        }
        vector<int> numsSameConsecDiff(int N, int K) {
            vector<int> ret;
            if(N==1)return {0,1,2,3,4,5,6,7,8,9};
            if(K==0){
                int temp = 1;
                for(int i = 1; i < N; ++i){
                    temp *= 10;
                    ++temp;
                }
                for(int i = 1; i <= 9; ++i){
                    ret.push_back(temp*i);
                }
                return ret;
            }
            for(int i = 1; i <= 9; ++i){
                int n = 1;
                int cur = i;
                backtrace(ret,cur,n,N,K);//已经完成了n位
            }
            return ret;
        }
    };