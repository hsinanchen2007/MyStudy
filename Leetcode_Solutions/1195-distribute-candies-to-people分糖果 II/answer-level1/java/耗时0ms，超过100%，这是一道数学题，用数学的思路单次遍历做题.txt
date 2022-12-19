这里对于第k次遍历，那么第i（1<=i<=n）个人i拿到的糖果是 (k-1)n + i.
第k次遍历n个人总共消耗的糖果是 n((2k-1)n+1)/2.
对于k次遍历之和，那么第i个人拿到的总糖果数是  k(k-1)n/2 + ik. 
k次遍历之和，n个人总消耗的糖果是 (kn+1)kn/2

![image.png](https://pic.leetcode-cn.com/d7d8539151e93d413bae4d4afce805ff4e719be50fd8749b6fd41577701ac3b3-image.png)

这里首先找出k 使得 (kn+1)kn/2 <= candies < ((k+1)n + 1)(k+1)n/2.也即刚好能完成k次遍历的小于candies的糖果数，然后依照公式将各个人的糖果数计算并赋值，多余糖果量 candies - (kn+1)kn/2依次按照公式加给各人，最后不足一人的全部给该个人。

```
public class solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = num_people;
        int[] res = new int[n];
        if(n == 0) return res;
        int k = 1,rest = candies;
        int sum = (n*((2*k-1)*n+1))/2;
        while(sum < candies){
            k++;
            rest = candies - sum;
            sum += (n*((2*k-1)*n+1))/2;
        } 
        k--;
        sum = 0;
        for(int i = 0; i < n; i++){
            res[i] = k*(k-1)*n/2 + k*(i+1);
            if(sum + k*n + i+1 <= rest){
                res[i] += k*n +i +1;
                sum += k*n + i+1;
            }else{
                res[i] += rest - sum;
                sum = rest;
            }
        }
        return res;
    }
}
```

