### 解题思路


### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int hash[80000]={0};
        for(int i=0;i<A.size();i++){
            hash[A[i]]++;
        }
        int move=0;
        for(int i=0;i<80000;i++){
            if(hash[i]>1){
                for(int j=i+1;hash[i]!=1&&j<80000;j++){
                    if(hash[j]==0){
                        hash[j]++;
                        hash[i]--;
                        move+=j-i;
                    }
                }
            }
        }
        return move;
    }
};
```