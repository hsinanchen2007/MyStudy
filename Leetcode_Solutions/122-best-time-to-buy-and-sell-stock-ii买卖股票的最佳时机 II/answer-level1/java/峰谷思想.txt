废话不多说，直接上代码，自己写完后发现跟答案思想一样，但是不知道为什么执行的时候总是1ms、100%，给我整的有点懵了。。。
```
public int maxProfit(int[] prices) {
        int index = 0, n = prices.length;
        int peak = 0;
        int valley = 0;
        int max = 0;
        while(index < n){
            while(index < n - 1 && prices[index] >= prices[index + 1] ){
                index++;
            }
            valley = index;
            while(index < n - 1 && prices[index] <= prices[index + 1]){
                index++;
            }
            peak = index;
            if(prices[peak] - prices[valley] >= 0){
                max += prices[peak] - prices[valley];
            }
            index++;
            
        }
        return max;
        
    }
```

![无标题.png](https://pic.leetcode-cn.com/528451135e26cc43a53b0b024c3bf0af56c9d7a58a8fa158ce6d825ba418d64d-%E6%97%A0%E6%A0%87%E9%A2%98.png)

图片简略画的，数值不重要，大概说一下，图中连续的三组峰谷，峰谷差值和就是最大的利润，在看官解评论有问忽略一次的利润来换取更大的利润的说法，可以看成是三条谷到峰的线段，最大就是直接加到一起，而忽略一次的利润相当于把线段重叠之后再加到一起，如下图。
![无标题.png](https://pic.leetcode-cn.com/11bc4c8617d9e34d55d6b5d2e0912719438fd74fee5d93b4cecae89dc4c7471a-%E6%97%A0%E6%A0%87%E9%A2%98.png)

