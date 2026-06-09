假设 N=由 区间 $[a,a+k-1]$ 累加得到  等差数列 首项为 $a$  ，项数 为 $k$  

其中  $a>=1$，$k>=1$  且都为整数

$N=(a+a+k-1)*k/2$

-> $a*k=N-(k-1)*k/2$

-> $(k-1)*k/2<N$ && $(N-(k-1)*k/2 )$ 能被 $k$ 整除  

```Java

class Solution {
  public int consecutiveNumbersSum(int N) {

        int count=0;
        for(int i=1;(i-1)*i/2<N;i++){
            int tmp=N-(i-1)*i/2;
            if(tmp%i==0){
                count++;
            }
        }
        return count;
    }
}
```