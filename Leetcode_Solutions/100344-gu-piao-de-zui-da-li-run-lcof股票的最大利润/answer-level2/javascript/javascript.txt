```
var maxProfit = function(prices) {
  let start=prices[0];
  let price=0;
  for(let i=0;i<prices.length;i++){
    if(prices[i]<start){
      start=prices[i];
    }
    price=Math.max(price,prices[i]-start)
  }
  return price
};
```
