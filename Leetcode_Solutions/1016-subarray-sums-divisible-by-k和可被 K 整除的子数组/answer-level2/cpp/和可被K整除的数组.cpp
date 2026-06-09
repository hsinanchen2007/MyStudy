![image.png](https://pic.leetcode-cn.com/8e25809cd0d54c623ea8ae5b67c6a37d887f4be77b093b01acedf8a6ae550773-image.png)

前缀数组是求连续子序列的一个套路，但是自己始终掌握的不是很好

```
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum=0,res = 0;
        int P[A.size()+1];
        memset(P,0,sizeof(P));
        P[0] = sum;
        for(int r=1;r<A.size()+1;r++){
           sum += A[r-1];
           P[r] = sum; 
        }
         
        int count[K];
        memset(count,0,sizeof(count));
        for(int a=0;a<A.size()+1;a++){
            count[(P[a]%K+K)%K]++;//为啥不是P[a]%K的原因是除去负数的存在
        }

        for(int j=0;j<K;j++){
            res+=(count[j]*(count[j]-1))/2;
        }
        
        return res;
    }
};

```
