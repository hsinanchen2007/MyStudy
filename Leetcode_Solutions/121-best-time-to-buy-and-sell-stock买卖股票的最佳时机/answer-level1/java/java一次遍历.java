执行用时 :1 ms, 在所有 Java 提交中击败了99.90%的用户
### 一次遍历
使用一个变量currPri存储最便宜的股票价格，遍历数组，如果遇到更便宜的股票，买入，即改变currPri的值。如果当前股票更贵，计算此时的利润并和之前存储的利润比较。
细节可以看代码中的注释:

```java
public int maxProfit(int[] prices) {
    if(prices.length == 0 || prices == null) return 0;
    //利润
    int pro = 0;
    //当前股票价格
    int currPri = prices[0];
    //遍历数组
    for(int i = 1; i < prices.length; i++) {
       //如果当前股票价格比上个月的便宜，买入
       if(currPri > prices[i]) {
	  currPri = prices[i];
       }else {
	  //如果当前股票更贵，计算卖出的利润
	  int tempPro = prices[i] - currPri;
	  //如果利润大，改变pro值
	  if(tempPro > pro) {
	     pro = tempPro;
	  }
       }			
    }
    return pro;
}
```