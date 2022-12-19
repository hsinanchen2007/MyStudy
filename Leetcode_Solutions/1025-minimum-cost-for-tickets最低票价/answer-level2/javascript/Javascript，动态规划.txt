思路：动态规划。

函数leastCost(i)为，第i天最最后一天旅游的最低消费。

那么leastCost(i)等于多少呢？

首先，如果第i天不用旅游，那明天leastCost(i) = leastCost(i + 1), 今天不旅行，晚一天买票不会亏；

如果第i天需要旅游，那么今天你必须买票，而且只能买日、周、月票其中之一。那么:

 ```
leastCost(i) = Math.min(
        leastCost(i + 1) + costs[0], 
        leastCost(i + 7) + costs[1], 
        leastCost(i + 30) + costs[2]
    );
```

题解：
```
var mincostTickets = function(days, costs) {
   return leastCost(1);
   
   /**
    * 第i天到最后一天的最小花费;
    */
   function leastCost(i) {
       /**
        * 超过365天就视为不用钱了；因为i不能大于365
        */
       if( i > 365 ) return 0;
       /**
        * 如果今天不是旅行日那：leastCost(i) === leastCost(i + 1);
        * 今天不旅行，晚一天买票不会亏；
        */
       if( isTravelDay(i) ) {
           return Math.min(leastCost(i + 1) + costs[0], leastCost(i + 7) + costs[1], leastCost(i + 30) + costs[2]);
       } else {
           return leastCost(i + 1);
       }
   }
   
   function isTravelDay(i) {
       return days.indexOf(i) > -1;
   }
};
```