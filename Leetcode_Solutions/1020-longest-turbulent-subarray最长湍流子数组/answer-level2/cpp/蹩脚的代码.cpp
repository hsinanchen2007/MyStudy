### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res = 1;
        int tempValue = 0;
        int i = 0;
        //for(int i = 0; i < A.size()-1; i++) {
        while(i < A.size() - 1) {
            tempValue = tempMaxSize(i, A);
            res = max(res, tempValue);
            int s = i + tempValue - 1;
            if(s != i) {
                i = s;
            } else {
                i = i + 1;
            }
        }
        return res;
    }
    int tempMaxSize(int i, vector<int>& A)
    {
        if(i == A.size()-1) {
            return 1;
        }
        int flag;
        int temp = 1;
        if(A[i] > A[i+1]) {
            flag = 1;
            temp++;
        } else if(A[i] < A[i+1]) {
            flag = 0;
            temp++;
        } else {
            flag = 2;
        }
        for(int j = i+1; j < A.size()-1; j++) {
            if(flag == 1) {
                if(A[j] < A[j+1]) {
                    temp++;
                    flag = 0;
                } else {
                    return temp;
                }
            } else if(flag == 0) {
                if(A[j] > A[j+1]) {
                    temp++;
                    flag = 1;
                } else {
                    return temp;
                }
            } else {
                return temp;
            }
        }
        return temp;
    }
};
```