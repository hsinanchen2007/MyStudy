```
class Solution {
    public int maxProfit(int[] prices) {
        
        //先找低谷、接着找高峰、一直到数组尾部
        int index = 0, length = prices.length, profit = 0;
        while(index < length-1){
            while(index<length-1 && prices[index]>=prices[index+1]){ index++;}
            
            //如果一直是下坡，或者一坡滑到底，则返回profit
            if(index==length-1) return profit;
            
            //此时index你就是低谷了，记录你的值，我们要开始找高峰了
            int low = prices[index];
            
            while(index<length-1 && prices[index]<prices[index+1]){ index++;}
            //此时index就变成高峰了，记录此刻的值，我们要开始循环了
            int high = prices[index];
            profit += (high - low);
        }
        return profit;
    }
}
```
