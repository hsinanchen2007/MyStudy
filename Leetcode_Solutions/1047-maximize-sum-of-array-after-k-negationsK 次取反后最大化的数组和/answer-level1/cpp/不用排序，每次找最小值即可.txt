```
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size()==0) return 0;
        int sum = 0;
        for(auto a : A) sum += a;
        while(K>0)
        {
            int min = A[0], idx = 0;
            for(int i=0;i<A.size();i++)
            {
                if(A[i] < min)
                {
                    min = A[i];
                    idx = i;
                }   
            }
            A[idx] = -min;
            sum -= 2 * min;
            K--;
        }
        return sum;
    } 
};

```