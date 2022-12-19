```
class Solution {
public:
	double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		int m=A.size(), n=B.size();
		int ab[2]={0,0};
		for(int i=0, j=0, k=0; (i<m || j<n) && k<=(m+n)/2; ++k){
			swap(ab[0],ab[1]);
			if(i>=m) ab[1]=B[j++];
			else if(j>=n) ab[1]=A[i++];
			else ab[1]=A[i]<B[j]?A[i++]:B[j++];
		}
		if((m+n)&1) return ab[1];
		else return (ab[0]+ab[1])/2.0;
	}
};
```
