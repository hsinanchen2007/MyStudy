![1571645166.png](https://pic.leetcode-cn.com/61cb424a55a390e8e8a1e8c9b80c8e26fcb56a839934f21d4084ffdb02a770cd-1571645166.png)

```
class Solution {
    public int minCost(int[][] costs) {
        int len = costs.length;
        if(len == 0){//数组为0返回0
            return 0;
        }

        //累计至当前的房子所花费费用
        //如果当前为红色，那么上一个只能是另外两种颜色，加上其中的最小值即可
        for(int i=1;i<len;i++){
            costs[i][0] += Math.min(costs[i-1][1],costs[i-1][2]);
            costs[i][1] += Math.min(costs[i-1][0],costs[i-1][2]);
            costs[i][2] += Math.min(costs[i-1][0],costs[i-1][1]);
        }
        return getMin(costs[len-1][0],costs[len-1][1],costs[len-1][2]);
    }
    
    public int getMin(int num1,int num2,int num3){//返回三个数中的最小值
        int min1 = Math.min(num1,num2);
        return Math.min(min1,num3);
    }
}
//菜狗解析，有意见指出，有问题call我
```

