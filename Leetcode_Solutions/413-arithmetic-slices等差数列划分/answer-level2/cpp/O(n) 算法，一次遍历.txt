```C++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if( n < 3 ) return 0;
        
        int result = 0;
        int begin = 0, progress = A[1] - A[0];
        for(int i = 2; i < n; i++) {
           if( A[i] - A[i-1] == progress ) {
               result += (i - begin) > 1? (i - begin - 1) : 0;
           } else {
               begin = i - 1;
               progress = A[i] - A[i-1];
           }
        }
        return result;
    }
};
```