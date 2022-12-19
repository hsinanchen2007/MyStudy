### 解题思路
此处撰写解题思路
思路1： 暴力法一次尝试
在第一天购买(price[0])，在第二天到最后一天的最大值售出（第一天之后的最大值）计为max[0]
在第二天购买，在第三天到最后一天的最大值售出（第二天之后的最大值）
....
在第N-1天购买，第N-1天之后的最大值max[N-1]

依次尝试找到最大的利润，如果利润都为负，那么利润为0
那么需要计算max[0]到max[N-1]
那么计算 公式一 是：
Math.max(max[0]-price[0],....,max[N-1]-price[N-1])

那么分别计算max[i]的复杂度是O(N)
整个的时间复杂度是O(N^2) 空间复杂度是O(N)

思路2： 在思路1的基础上进行优化
因为max[i]的计算是可以递推的

max[i] = Math.max(prices[i+1], max[i+1])
因此可以先计算出max[1..N-1]  再计算最终结果
整个的时间复杂度是O(N) 空间复杂度是O(N)

思路3：由于遍历一遍不可避免，这个思路时间复杂度基本上是O(N)，那么空间复杂度是否可以优化。

我们可以看到公式一 的循环，max的值只使用一次，存在优化的可能。而max的值是下标从大到小递推。

因此，我们可以直接计算公式一，并且按照max[N-1]-price[N-1] 到max[0]-price[0] 的顺序。

只用一个变量记录，数组max[i].



### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int ret = 0;
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int N = prices.length;
        int max = prices[N-1];
        for (int i = N-2; i >= 0; i--) {
            int buy = prices[i];
            int sell = max;
            ret = Math.max(ret, sell - buy);
            max = Math.max(prices[i], max);
        }
        return ret;
    }
}
```

简化一下

```java
class Solution {
    public int maxProfit(int[] prices) {
        int ret = 0;
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int N = prices.length;
        int max = prices[N-1];
        for (int i = N-2; i >= 0; i--) {
            ret = Math.max(ret, max - prices[i]);
            max = Math.max(prices[i], max);
        }
        return ret;
    }
}
```

对比了一下官方正向遍历的方法，好像速度比他慢一点，复杂度是一样。 就在这里面的if和else。

可以简化一些情况，当 我们打算在 prices[i] 购买的时候， 如果 prices[i]的价格比max的价格还要高，就不要进行利润的计算，而prices[i]与 max的比较不可避免。

```java
class Solution {
    public int maxProfit(int[] prices) {
        int ret = 0;
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int N = prices.length;
        int max = prices[N-1];
        for (int i = N-2; i >= 0; i--) {
            if( prices[i] > max) {
                max = prices[i]; 
            } else {
                ret = Math.max(ret, max - prices[i]);
            }
        }
        return ret;
    }
}
```