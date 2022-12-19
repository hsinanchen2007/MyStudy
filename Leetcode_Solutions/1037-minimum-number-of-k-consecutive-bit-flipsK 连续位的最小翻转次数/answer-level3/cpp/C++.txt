### 解题思路
能迭代就别递归，否则你会和我一样慢

### 代码

```cpp
class Solution {
public:
    int mark[30010],flip=0;
    int reverse(vector<int>& A,int K,int i){
        if(i+K>A.size())return 0;
        if(mark[i])flip=!flip;
        if(!(A[i]^flip)){
            flip=!flip;
            mark[i+K]=1;
            return reverse(A,K,i+1)+1;
        }
        return reverse(A,K,i+1);
    }
    int minKBitFlips(vector<int>& A, int K) {
        int ans=reverse(A,K,0);
         for(int i=A.size()+1-K;i<A.size();i++){
             if(!(A[i]^flip^mark[i]))return -1;
             if(mark[i])flip=!flip;
             }
        return ans;
    }
};
```