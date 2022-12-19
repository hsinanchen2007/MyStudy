```
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);                      //用于收尾，最后一级 也可在最后return min(curr, pre);
        int pre = 0, curr = 0;                  //存放前两级台阶的花费,初始为0
        for(int c : cost){                      //遍历
            int temp = curr;                    //暂存curr
            curr = min(pre, curr) + c;          //状态转移方程（顺便更新curr）
            pre = temp;                         //更新pre
        }
        return curr;
    }
```


