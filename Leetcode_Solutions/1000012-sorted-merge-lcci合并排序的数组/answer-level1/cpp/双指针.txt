使用双指针，要注意的是插入元素导致的A的大小的变化和删除末尾的0
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int p=0,q=0;
        while(p<m&&q<n){
            if(A[p]>=B[q]){
                A.insert(A.begin()+p,B[q++]);
                A.pop_back();m++;
            }
            else{
                p++;
            }
        }
        if(p==m)while(q<n)A[p++]=B[q++];
    }
};
```
