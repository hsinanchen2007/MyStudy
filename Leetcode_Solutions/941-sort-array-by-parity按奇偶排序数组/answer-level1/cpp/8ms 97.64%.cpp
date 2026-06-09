### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int beg = 0;
        int end = A.size() - 1;
        while(beg <= end){
            while(beg <= end && A[beg] % 2 == 0){
                beg++;
            }
            while(end >= beg && A[end] % 2){
                end--;
            }
            if(beg <= end){
                swap(A[beg],A[end]);
                beg++;
                end--;
            }
        }
        return A;
    }
};
```