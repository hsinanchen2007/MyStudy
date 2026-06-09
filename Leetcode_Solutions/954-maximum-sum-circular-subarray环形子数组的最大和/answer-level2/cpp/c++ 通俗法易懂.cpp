### 解题思路
环时，最大值可能为(全部值和-最小序列值和)；
进行比较判断即可。
### 代码

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sizz=A.size();
        if(sizz==0){
            return 0;
        }
        int sum=A[0],summ=A[0],maxx=A[0],minn=0,all=A[0];
        for(int i=1;i<sizz;i++){
            sum=max(A[i],sum+A[i]);
            maxx=max(sum,maxx);//记录最大序列值

            summ=min(A[i],summ+A[i]);
            minn=min(summ,minn);//记录最小序列值

            all+=A[i];//记录全部值
        }
        return maxx<0?maxx:max(maxx,all-minn);
    }
};
```