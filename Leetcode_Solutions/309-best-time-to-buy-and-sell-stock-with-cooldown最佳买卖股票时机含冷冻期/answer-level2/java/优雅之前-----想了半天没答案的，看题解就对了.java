// 有时候觉得，要是不看别人是怎么做的，可能自己一辈子都想不出来，
// 状态转移是重点也是难点；
// 用持有、未持有（这两种情况下的最大利润），两个数组来刻画这个状态转移过程；
// 冷却时间直接在状态转移方程中体现；




```
       int ret = 0;
       int n = prices.length;
       int[] hold = new int[n];
       int[] noHold = new int[n];
       if(n<2){
            return ret;// 不够一个周期，所以啥都没做；
        }else{
          hold[0] = -prices[0];
          hold[1] = Math.max(hold[0],-prices[1]);
      
          noHold[0] = 0;
          noHold[1] = Math.max(hold[0]+prices[1],0);

          for(int i = 2;i<n;i++){
              hold[i] = Math.max(noHold[i-2]-prices[i],hold[i-1]);
              noHold[i] = Math.max(hold[i-1]+prices[i],noHold[i-1]);
          }
       }
       return noHold[n-1]; 
```
