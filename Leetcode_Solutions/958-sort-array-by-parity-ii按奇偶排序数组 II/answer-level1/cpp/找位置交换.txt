```
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int pre1=1,pre2=0,aLen=A.size();
        while( true ) {
            while(  pre2<aLen &&  !(A[pre2] & 1) ) pre2+=2;//找到 不是偶数但又是偶数索引
            while(  pre1<aLen && A[pre1] & 1  ) pre1+=2;//找到 不是奇数但 是奇数索引
            if( pre1 < aLen || pre2<aLen )
                swap(A[pre1],A[pre2]);
            else
                break;
        }
        return A;
    }
};
```
