```
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size(),re = 0,m,top;
        stack<int>pos;
        pos.push(0);
        for(int i=1;i<n;i++){
            top = pos.top();
            m = A[i]+A[top]+top-i;
            re = max(re,m);
            if(A[top] < A[i] || i-top > A[top]-A[i]){
                pos.pop();
                pos.push(i);
            }
        }
        return re;
    }
};
```
