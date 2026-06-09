### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        stack<int> s;
        int i = 0,j = A.size() - 1,cur = A.size() - 1;
        while(i <= j){
            if(A[i]*A[i] < A[j]*A[j]){
                res[cur--] = A[j]*A[j];
                j--;
            }
            else{
                res[cur--] = A[i]*A[i];
                i++;
            }
        }
        return res;
    }
};




```