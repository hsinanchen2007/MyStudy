代码和官方给出的基本上没有区别，主要是官方描述的让人摸不着头脑，我在这里重新讲一下。
较小的要加K，较大的要减K，那么就形成了两端递增的序列，两个递增序列的话就有两个极大
值和两个极小值，最大值由两个极大值来争（假如在i处分割，则是A【i】+K和A【length-1】
-K），同理最小值由A【0】+K和A【i+1】-K来争，现在就剩一个问题了，即怎么找到那个分割
点，但是分割点没有什么特殊的性质，我们通过遍历所有的可能性最合适的分割点，其实也就是
最大值最小值的差值最小的时候，当然我们最后不是要返回分割点是什么，而是最小差值。


```
class Solution {
    public int smallestRangeII(int[] A, int K) {
        int length = A.length;
        Arrays.sort(A);
        int res=A[length-1]-A[0];
        for (int i = 0; i < length-1; i++) {
            int max=Math.max(A[i]+K,A[length-1]-K);
            int min=Math.min(A[0]+K,A[i+1]-K);
            res=Math.min(res,max-min);
        }
        return res;
    }
}
```
