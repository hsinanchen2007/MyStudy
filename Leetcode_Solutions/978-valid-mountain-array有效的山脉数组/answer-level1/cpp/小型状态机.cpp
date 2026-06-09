### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int state = 0;
        for(int i=1;i<A.size();i++){
            switch(state){
                case 0:
                    if(A[i]>A[i-1]) state = 1;
                    else return false;
                    break;
                case 1:
                    if(A[i]<A[i-1])state = 2;
                    else if(A[i]==A[i-1])return false;
                    break;
                case 2:
                    if(A[i]>=A[i-1])return false;
                    break;
            }
        }
        return state == 2;
    }
};
```