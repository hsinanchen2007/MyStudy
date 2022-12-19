### 暴力

```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i = m, j = 0; i < m + n && j < n; i++,j++){
            A[i] = B[j];
        }
        sort(A.begin(), A.end());
    }
};
```

### 正向双指针，借助辅助数组

```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = 0, j = 0;
        int temp[m + n];
        int cur;
        while (i < m || j < n) {
            if (i == m)
                cur = B[j++];
            else if (j == n)
                cur = A[i++];
            else if (A[i] < B[j])
                cur = A[i++];
            else if(A[i] >= B[j])
                cur = B[j++];
            temp[i + j - 1] = cur;
        }
        for (int k = 0; k < (m + n); ++k)
            A[k] = temp[k];
    }
};
```
### 逆向双指针，无需借助辅助数组，运行用时0ms
有一个疑惑🤔 如果测试用例给两个从大到小排序的数组呢？又或者一个从大到小另一个从小到大呢？🤫

```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        while(m > 0 && n > 0){
            if(A[m - 1] > B[n - 1]){
                A[m + n - 1] = A[m - 1];
                m--;
            }
            else{
                A[m + n - 1] = B[n - 1];
                n--;
            }      
        }
        while(n > 0){
            A[n - 1] = B[n - 1];
            n--;
        }
    }
};
```


