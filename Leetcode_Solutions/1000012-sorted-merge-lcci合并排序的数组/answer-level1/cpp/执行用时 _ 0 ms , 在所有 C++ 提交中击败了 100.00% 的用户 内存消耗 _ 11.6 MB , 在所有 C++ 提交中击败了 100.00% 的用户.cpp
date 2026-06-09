#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
    	A.erase(A.begin()+m, A.end());
    	A.insert(A.begin(), B.begin(), B.begin()+n);
    	sort(A.begin(),A.end());
    }
};


int main()
{
	int a[] = {1,2,3,0,0,0};
	int b[] = {2,5,6};
	Solution s;
	vector<int> A (a, a+6);
	vector<int> B (b, b+3);
	s.merge(A, 3, B, 3);
	
	for(int i=0; i < A.size(); ++i)
		cout << A[i] << " ";
	
	
	
	return 0;
}