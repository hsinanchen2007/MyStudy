状态设计很重要，第一次写的时候忽略了k，但其实不同的k，会对每个位置的prob带来的影响。
```
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> probs(N, vector<vector<double>>(N, vector<double>(K+1, 2.0)));
        return knightProbabilityUtil(probs, N, K, r, c);
         
    }
    double knightProbabilityUtil(vector<vector<vector<double>>>& probs, int N, int K, int r, int c){    
        if(r < 0 || r >= N || c < 0 || c >= N) return 0;
        if( K == 0) return 1;

        if(probs[r][c][K] == 2.)
        {
            double prob = knightProbabilityUtil(probs, N, K-1, r+1, c-2) + knightProbabilityUtil( probs, N, K-1, r-1, c-2) + knightProbabilityUtil(probs, N, K-1, r+1, c+2) + knightProbabilityUtil(probs, N, K-1, r-1, c+2) + knightProbabilityUtil(probs, N, K-1, r+2, c-1) + knightProbabilityUtil(probs, N, K-1, r+2, c+1) + knightProbabilityUtil(probs, N, K-1, r-2, c-1) + knightProbabilityUtil( probs, N, K-1, r-2, c+1);
            probs[r][c][K] = prob / 8. ; 
        } 
        return probs[r][c][K];
    }
};
```
