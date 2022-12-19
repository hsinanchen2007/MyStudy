```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i=0,j=1;i<A.size();i+=2){
        	if(A[i]%2==1){
        		while(A[j]%2==1)j+=2;
        		swap(A[i],A[j]);
			}
		}
		return A;
    }
};
```
