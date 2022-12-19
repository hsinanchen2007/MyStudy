int repeatedNTimes(vector<int>& A) {
	set<int> s;
	for(int i = 0;i<A.size();i++) {		
	s.insert(A[i]);
	if(i!=s.size()-1)
		return A[i];
	} 
	return 0;
    }