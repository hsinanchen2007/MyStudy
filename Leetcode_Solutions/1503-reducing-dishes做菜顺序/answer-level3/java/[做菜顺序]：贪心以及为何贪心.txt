### 做菜顺序一定按升序

题目说可以按任意顺序做菜并且可以选做，我们就假设选择做所有的菜，按什么顺序总和最大呢？很显然要按 `s` 升序来做，因为在时间序列一定是自然数序列的情况下，大数*大数是更大的。

> 简单证明一下，定义 `s` 升序排列后为 {s[1],s[2],s[3]……s[N]},假设我们不按升序排列做菜，意味在计算 $sum(t[i]*s[i])$ 时，存在：$s[i1]>s[i2]  且  t[i1]<t[i2]$ .
>
> 那我们一定可以交换 i1,i2 两道菜的顺序来得到更大的【喜爱时间】，即$s[i2]*t[i1]+s[i1]*t[i2]> s[i1]*t[i1]+s[i2]*t[i2]$  (自行推理，很简单)

经过这番思考其实你发现，这个顺序与选做几道菜无关，无论选几道菜，总是要按升序去做。

### 不管选做几道菜，总是选最大的那几道。

依然定义 `s` 升序排列后为 ${s[1],s[2],s[3]……s[N]}$

如果只选一道菜，毫无疑问选最大的s[N].

如果两道呢？应该选 s[N-1] 和 s[N] 。

如果选 K 道菜，应该选 s[N-K+1] 到 s[N]。

> 依然是反证法，假设不这样选，意味着选菜里存在s[i],i<N-k+1,那必然存在 s[j],j>=N-k+1 没被选，那我们必然可以选 j 而不选 i 来得到更大的【喜爱时间】。



到这里已经很清晰了，分别算出选做 1、2、……N 道菜的【喜爱时间】，取最大值即可。

### 小技巧

【喜爱时间】的计算是可以递推的，设选做 K 道菜的喜爱时间为 happy[k]

$happy[0]=0$

 $happy[1]=s[N]*1$

 $happy[2]=s[N-1]*1+s[N]*2$

 $happy[3]=s[N-2]*1+s[N-1]*2+s[N]*3$

……

happy[1]与 happy[0]差一个s[N]

happy[2]与 happy[1]差一个s[N-1]+s[N],

happy[3]与 happy[2]差一个s[N-2]+s[N-1]+s[N] 



### 附上 java

```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int ans=0;
        int helperSum=0;
        int satis=0;
        for(int i=satisfaction.length-1;i>=0;i--){
            helperSum+=satisfaction[i];
            satis+=helperSum;
            ans=Math.max(satis,ans);
        }
        return ans;
    }
}
```


