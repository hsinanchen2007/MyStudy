### 解题思路
亲测，使用逐个计算，然后重新排序的方法必然超时。
算法：
1、将前面相同的数字，插入后面出现的空隙之中；
2、最后还剩下数字的话，统一放到最后一个数字后面。
如果不理解的话，请看官方题解，讲的很好。

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
       if (A.size()==0 || A.size()==1) return 0;
       int ans=0, taken=0;
       sort(A.begin(), A.end());
       for (int i=1; i<A.size(); i++){
           if (A[i]==A[i-1]){//统计相同的数字
               ans-=A[i];
               taken++;
           }
           if (A[i]>A[i-1]){//插入这个空隙中
               int give=min(taken, A[i]-A[i-1]-1);
               ans+=give*(give+1)/2 +give*A[i-1];
               taken-=give;
           }
       }
       if (taken>0){
           ans+=taken*(taken+1)/2+taken*A.back();
       }
       return ans;
    }
};
```