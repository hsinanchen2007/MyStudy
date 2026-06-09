class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int e=A.size()-1;
        if(A[e]-A[0]<=2*K)
            return 0;
        return A[e]-K-(A[0]+K);
    }
};