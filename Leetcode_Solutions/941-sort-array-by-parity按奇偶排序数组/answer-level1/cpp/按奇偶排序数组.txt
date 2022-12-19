【 36 ms - 97.60% ，9.5 MB - 94.94% 】

左指针寻找奇数，右指针寻找偶数，再进行交换。

```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while(i<j){
            while(A[i]%2==0&&i<j)  i++;
            while(A[j]%2==1&&i<j)  j--;
            swap(A[i],A[j]);
        }
        
        return A;
    }
};
```