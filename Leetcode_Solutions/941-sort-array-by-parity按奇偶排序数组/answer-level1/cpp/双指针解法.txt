```
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() == 1){
            return A;
        }
        int L = 0;
        int R = 1;
        int len = A.size();
        while(L<=R){
            if(A[L]%2 == 1 && A[R]%2 == 0){
                swap(A[L], A[R]);
                L++;
                R++;
                if(L == len || R == len){
                    break;
                }
            }
            if(A[L]%2 == 1 && A[R]%2 == 1){
                R++;
                if(R == len){
                    break;
                }
            }
            if(A[L]%2 == 0 && A[R]%2 == 0){
                L++;
                if(L == R){
                    R++;
                    if(R == len){
                        break;
                    }
                }
                if(L == len){
                    break;
                }
            }
            if(A[L]%2 == 0 && A[R]%2 == 1){
                L++;
                R++;
                if(L == len || R == len){
                    break;
                }
            }
        }
        return A;
    }
};
```
![3.png](https://pic.leetcode-cn.com/54d535980866d5125660eab3ad648193cbe47172bc904557b9688f3a9717b08e-3.png)
