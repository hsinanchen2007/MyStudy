vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for(int i = 0; i < A.size(); i++){
        int beg = 0;
        int end = A[0].size() - 1;
        while(beg <= end){
            if(A[i][beg] == A[i][end]){
                if(A[i][beg] == 1){
                    A[i][beg] = 0;
                    A[i][end] = 0;
                }
                else{
                    A[i][beg] = 1;
                    A[i][end] = 1;
                }
            }
            beg++;
            end--;
        }
    }
    return A;
}