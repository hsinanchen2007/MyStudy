i指针遍历偶数位置，j指针遍历奇数位置，遍历过程寻找i上的奇数和j上的偶数交换即可。
```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0, j = 1; i < A.size() && j < A.size();){
            while(i < A.size() && A[i] % 2 == 0) i += 2;
            while(j < A.size() && A[j] % 2 == 1) j += 2;
            if(i < A.size() && j < A.size()) swap(A[i],A[j]);
        }
        return A;
    }
};
```
