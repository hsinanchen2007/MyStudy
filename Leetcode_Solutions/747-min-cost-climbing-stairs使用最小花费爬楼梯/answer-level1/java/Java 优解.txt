例：对于第一个台阶，耗费的最少体力就是第-2和-1个台阶的最小值（如果不是最后一个台阶则必须加上翻过该台阶的体力）

我自认为此题题目描述有问题，明明说是登顶，最后一台阶却可以跨过去，所以我在最后一个台阶处做了处理
```
    public int minCostClimbingStairs(int[] cost) {
        //记录翻过当前台阶的前面第二个台阶的耗费的体力值 ： f(-2) 
        int pre = 0;
        //记录翻过当前台阶的前一个台阶耗费的体力值 ：f(-1)
        int cur = 0;
        for(int n = 0;n <= cost.length;n++){
            //此处强行在最后一个台阶后面再加一个台阶，这个台阶耗费的体力为0，用于可能出现翻过最后一个台阶的情况
            if(n == cost.length){
                cur = Math.min(pre,cur);
                break;
            }
            //简单来说，下面三行代码就是将pre一个一个台阶的向前上，保持pre一直在cur的前一个台阶，cur记录翻过当前台阶耗费的最小体力
            int temp = cur;
            cur = Math.min(pre,cur) + cost[n];
            pre = temp;
        }
        return cur;
    }
```

不懂的可以评论，会回复
