逆向双指针：
- 时间复杂度：o(m+n),遍历一遍
- 空间复杂度：o(1),原地
```cpp []
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int p=m+n-1,a=m-1,b=n-1;
        while(a>=0 && b>=0){
            if(A[a]>=B[b]) A[p--]=A[a--];
            else A[p--]=B[b--];
        }
        while(a>=0) A[p--]=A[a--];
        while(b>=0) A[p--]=B[b--];
    }
};
```

