### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        Arrays.sort(A);
        for(int i=0;i<A.length;i++)
        {
            if(K>0&&A[i]<0)
            {
                A[i]=-A[i];
                K--;
            }
        }
        //此时如果K被用完了，那是最好的，如果K没有被用完。
        Arrays.sort(A);
        if(K%2!=0)   //还剩下的次数,K没被用完，说明剩下的都是正数了
            A[0]=-A[0]; //若剩下的是偶数次，相当于不变，奇数次可以只变1次
        int result=0;
        for(int num:A)
            result+=num;
        return result;
    }
}
```