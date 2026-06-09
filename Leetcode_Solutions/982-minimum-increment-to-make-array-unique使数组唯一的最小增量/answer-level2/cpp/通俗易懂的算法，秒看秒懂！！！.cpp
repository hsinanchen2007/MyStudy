### 解题思路
124ms+26.8ms
求大佬帮我改进一下
### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int move=0;
        if(A.size()<1)
        return 0;
        sort(A.begin(),A.end());
        for(int j=0;j<A.size()-1;j++){
            if(A[j]>=A[j+1]){
                move+=A[j]-A[j+1]+1;
                A[j+1]=A[j]+1;
            }
        }
        return move;
    }
};
```