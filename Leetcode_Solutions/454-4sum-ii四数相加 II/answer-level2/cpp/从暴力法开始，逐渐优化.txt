第一次，暴力版，超时无疑
```cpp
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      int N = A.size();
      int res = 0;
     // n^4
      for (int i = 0; i <N; ++i) {
        for (int j = 0; j <N; ++j) {
          for (int k = 0; k <N; ++k) {
            for (int p = 0; p <N; ++p) {
              if (A[i] + B[j] + C[k] + D[p] == 0) {
                res++;
              }
            }
          }
        }
      }
      return res;
    }
```
第二次，尝试做些cache，只想着最后算的快，无奈cache n^3，超时

```cpp
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      int N = A.size();
      int res = 0;
      unordered_map<int, int> m;
     // n^3
      for (int j = 0; j <N; ++j) {
        for (int k = 0; k <N; ++k) {
          for (int p = 0; p <N; ++p) {
            int tmp = B[j] + C[k] + D[p];
            if (m.count(tmp) > 0) {
              m[tmp] += 1;
            } else {
              m[tmp] = 1;
            }
          }
        }
      }
      for (int i = 0; i <N; ++i) {
        int tmp = 0-A[i];
        if (m.count(tmp) > 0) {
          res += m[tmp];
        }
      }
      return res;
    }k
```
final n^2做两次，过了

```cpp
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      int N = A.size();
      int res = 0;
      unordered_map<int, int> m;
      // n^2
      for (int k = 0; k <N; ++k) {
        for (int p = 0; p <N; ++p) {
        int tmp = C[k] + D[p];
        if (m.count(tmp) > 0) {
            m[tmp] += 1;
        } else {
            m[tmp] = 1;
        }
        }
      }
      
      for (int i = 0; i <N; ++i) {
        for (int j = 0; j <N; ++j) {
          int tmp = 0-A[i] - B[j];
          if (m.count(tmp) > 0) {
            res += m[tmp];
          }
        }
      }
      return res;
    }
```

