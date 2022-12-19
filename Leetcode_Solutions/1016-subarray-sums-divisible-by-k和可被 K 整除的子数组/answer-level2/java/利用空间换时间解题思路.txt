在做此题的时候首先想到空间换时间的常规思路。 

即先将数组A[i]转化为前i项和并且模K。 

例如A = [4,5,0,-2,-3,1], K = 5 

得到A = [4,4,4,2,4,0], 

然后借助辅助数组保存之前访问的各个模K值的结果的个数。 

大小为2K-1，对应的值分别为-K+1至k-1,然后做一个+(K-1)的映射,初试值全为0； 

然后遍历A，遍历方法如下： 

如果A[i]为0，代表当前值可被整除，则计数器+1,在查找i之前为0的个数，只需访问辅助数组fuzhu[0+K-1]。 

如果A[i]为正设为k，则查找i之前为k的个数或者为i-K的个数，再映射到数组下标fuzhu[i+K-1]和fuzhu[i-K+K-1]. 

依次类推，最终遍历结束可得结果。 

时间复杂度为O[N]，空间复杂度为O[2K-1]。 

代码如下: 

```
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int count = 0;   //计数器
        int[] fuzhu = new int[2*K-1];   //辅助数组
        for(int i = 0;i<2*K-1;i++) {
            fuzhu[i] = 0;
        }  //初始化
        A[0]%=K; 
        for(int i = 1;i<A.length;i++) {
            A[i]%=K;
            A[i] = (A[i-1] + A[i])%K;
        }
        for(int i : A) {
            if(i == 0) {
                count ++;
                count += fuzhu[0+K-1];
            }
            else if(i > 0) {
                count+=fuzhu[i+K-1];
                count+=fuzhu[i-K+K-1];
            }
            else if(i < 0) {
                count+=fuzhu[i+K-1];
                count+=fuzhu[i+K+K-1];
            }
            fuzhu[i+K-1] ++;
        }
        return count;
    }
}
```