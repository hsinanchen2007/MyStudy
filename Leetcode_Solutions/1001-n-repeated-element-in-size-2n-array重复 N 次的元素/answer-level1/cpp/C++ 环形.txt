参考评论区高赞。增加了首尾相等时的特判。
```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(int i=0;i<A.size()-1;++i){
            if(A[i]==A[i+1]) return A[i];
        }
        if(A[0]==A.back()) return A[0];
        return A[0]==A[2]?A[0]:A[1];
    }
};
```