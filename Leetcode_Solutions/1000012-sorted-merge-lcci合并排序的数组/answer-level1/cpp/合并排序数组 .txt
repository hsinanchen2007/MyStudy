### 解题思路
刚开始一直想着 两两对比之类的
看了其他大神的题解才顿悟从后面开始比较就好
既不用额外的空间，也比较容易理解

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1;
        int j=n-1;
        int cur=m+n-1;

        while(i>=0 && j>=0){
            if(A[i]>B[j]){A[cur]=A[i];cur--;i--;}
            else{A[cur]=B[j];cur--;j--;}
        }
        //执行到这一步表示上面一定有一组已经比较完了，所以剩下的是有序的直接放进去就可以
        while(i>=0){A[cur]=A[i];cur--;i--;}
        while(j>=0){A[cur]=B[j];cur--;j--;}

        
    }
};
```