### 解题思路
首选想到的就是暴力解题方法，逐个遍历找出差值最大的两个数字，代码如下:

### 方案一：
```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        for(int i = 0; i < prices.length - 1; i++){
            for(int j = i + 1; j < prices.length; j++){
                int profit = prices[j] - prices[i];
                if(maxProfit < profit){
                    maxProfit = profit;
                }
            }
        }
    }
}
```

时间复杂度：O(N^2)

方案一种的两层嵌套循环遍历中有大部分的遍历是没有意义的，比如示例数组`[7,1,5,3,6,4]`中当`i=0`时整个二层的遍历获得的数据都是小于0的，这种明显是无意义的循环，我们可以想办法优化这一块。

其实在循环遍历的过程中我们只关注相减数值大于0的数据，当发现`j`位置的数据小于`i`位置的数据时，那么`j`后面数据与`prices[i]`的差值肯定是小于与`prices[j]`的，即`（prices[j+x] - prices[i]）> (prices[j] - prices[i])`。因此我们可以将`i`直接移动到`j`的位置，从`j`的位置重新遍历，这样就省去了那些无效的遍历，代码如下：

### 方案二：

```java
class Solution {
   public int maxProfit(int[] prices) {
       int maxProfit = 0;
        for (int i = 0, j = 1; j < prices.length; j++) {
            int profit = prices[j] - prices[i];
            if (profit <= 0){
                i = j;
                continue;
            } else if (maxProfit < profit){
                maxProfit = profit;
            }
        }
       return maxProfit;
    } 
}
```

时间复杂度：O(N)

方案二算是从移动窗口思路转变过来的一种，借用两个“指针”（下标）一次遍历完数组找出最大的差值数据。看了别人的题解，还有一种不需要两个“指针”，遍历一次从而找出最大差值的方法，只需要记录遍历过程中找到的最小值（也比较符合现实中买卖股票的最理想的操作：从最低点买入，在后续的最高点卖出），然后后续的数据与之相减获取差值，再比较最大的差值。是一种更简洁优化的解法，代码如下：

### 方案三

```java
class Solution {
   public int maxProfit(int[] prices) {
       if(prices.length < 1)
            return;

       int minPrice = prices[0];
       int maxProfit = 0;
        for (int i = 1; i < prices.length; i++) {
            if(minPrice > prices[i]){
                minPrice = prices[i];
            } else if (maxProfit < prices[i] - minPrice){
                maxProfit = prices[i] - minPrice;
            }
        }
       return maxProfit;
    } 
}

```

时间复杂度：O(N)