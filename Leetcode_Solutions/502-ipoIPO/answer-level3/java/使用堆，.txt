### 解题思路
用一个最小堆存放项目，将资金小于w的项目，放入一个最大堆，然后取出最大堆里面的项目。

### 代码

```java
class Solution {
    private class MyNode{
    int profit;
    int capital;
    public MyNode(int capital,int profit){
        this.capital = capital;
        this.profit = profit;
    }
}

public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
    MyNode[] nodes = new MyNode[Profits.length];
    for (int i = 0; i < Profits.length; i++) {
        nodes[i] = new MyNode(Capital[i],Profits[i]);
    }
    PriorityQueue<MyNode> minCost = new PriorityQueue<>((o1, o2) -> o1.capital-o2.capital);
    PriorityQueue<MyNode> maxProfit =  new PriorityQueue<>((o1, o2) -> -(o1.profit-o2.profit));
    for (MyNode node:nodes){
        minCost.add(node);
    }
    /**
     *使用一个最小堆保存还能做的项目，每次将收益最大的拿出去然后循环k次
     */

    for (int i = 0; i < k ; i++) {
        while (!minCost.isEmpty() && minCost.peek().capital<=W){
            maxProfit.add(minCost.poll());
        }
        if(maxProfit.isEmpty()){
            return W;
        }else {
            W+=maxProfit.poll().profit;
        }
    }
    return W;
}

}
```