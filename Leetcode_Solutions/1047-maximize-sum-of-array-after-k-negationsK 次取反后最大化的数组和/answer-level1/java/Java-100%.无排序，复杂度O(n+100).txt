思路：将所有数字先求和**sum**，然后**number**数组记录所有负数出现的次数，**index**记录最小正整数，**i**从-100到-1.K>0时反转负数，比如**i**=-3变成+3，会使得sum增加2$\times$**i**$\times$**number**[i]。当K为0时返回结果，遍历结束后**K**如果仍然大于0，就检查它的奇偶性，若为奇数，就将最小的那个正数反转为负数
```
class Solution {
     public int largestSumAfterKNegations(int[] A, int K) {
        short[] number = new short[101];
        int sum = 0;
        int index = 100;
        for(int a:A){
            sum += a;
            if(a < 0){
                number[-a]++;
            }else{
                index = Math.min(index, a);
            }
        }
        int last = 100;
        for(int i = 100; i > 0; --i){
            if(number[i] == 0) continue;
            last = i;
            int c = Math.min(K, number[i]);
            sum += (i << 1) * c;
            if(K == c) return sum;
            K -= c;
        }
        if(K % 2 == 1){
            sum -= Math.min(index, last)<<1;
        }
        return sum;
    }
}
```
