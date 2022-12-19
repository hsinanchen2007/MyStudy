1、先将A排序
2、尽可能多的将负数反转（取决于K的个数）
3、反转后重新对A排序，并根据余下的K值将A[0]重复反转，直到次数用尽

  int largestSumAfterKNegations(vector<int> &A, int K) {
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] < 0 && K > 0) {
        A[i] = -A[i];
        K--;
      }
    }
    sort(A.begin(), A.end());
    while (K > 0) {
      A[0] = -A[0];
      K--;
    }

    for (int i = 0; i < A.size(); i++) {
        ans += A[i];
    }
    return ans;
  }