![image.png](https://pic.leetcode-cn.com/1cef7e5707d7f6658c2c6eaa06946f7accdd62485610ecddd9419d6ab9539a69-image.png)

```
/*
    题设：如果题目有解，该答案即为唯一答案。
    所以如果遍历一圈，total=total1+total2，则有解。其中total是起点前的总和，total1是终点前的总和；total2是终点前的总和
    这个解是从哪个start出发呢？只要我们在遍历过程中，当前的sum>0,说明sum+total1=total1+total2>0,说明就是解
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0,sum = 0, start = 0;
        for (int i = 0; i < gas.length; i++) {
            total +=gas[i] - cost[i];//转完整个圈，gas的总量要大于cost的总量才会有解；且是唯一解
            sum += gas[i]-cost[i];
            if (sum<0){
                start = i +1;
                sum = 0;
            }
        }
        return (total<0)?-1:start;
    }
```
