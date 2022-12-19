    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        if (A.size() == 0) {
            return 0;
        }
        
        if (A.size() == 1) {
            return 0;
        }
        
        int row = A.size(); // 行数
        int col = A[0].size(); // 列数
        
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row -1; j++) {
             bool a = A[j][i] <= A[j+1][i];
                if (a != true) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }