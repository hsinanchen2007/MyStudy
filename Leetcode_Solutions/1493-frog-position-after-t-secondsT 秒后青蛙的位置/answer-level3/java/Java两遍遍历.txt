由于是树，不必考虑闭环，每个chid只有一个parent
建立int[]path，和int[]from先遍历一边edges，将每个节点有几个子节点和每个节点的父节点信息存储
【顺便一提这里我遇到了第一个坑，edge的from和to并不是按大小排序的，因此后期又增加一次判断，保证父节点小于子节点】
之后再由下而上while循环一次，直到当前子节点为1，结束遍历，获取概率p和用时time
之后判断走到target的time与题给t大小关系，若t小于time，说明青蛙无法走到target，返回0
【这里我碰到了第二个坑，只要时间没到，青蛙就会继续走，所以time < t的情况还要判断target是否有子节点，若有，说明青蛙还会继续跳下去，概率变为0
```
class Solution {
    public double frogPosition(int n, int[][] edges, int t, int target) {
        int [] path = new int[n];
        int[] from = new int[n];
        for (int[] edge : edges) {
            path[(edge[0] < edge[1] ? edge[0] : edge[1])- 1]++;
            from[(edge[0] < edge[1] ? edge[1] : edge[0]) - 1] = edge[0] < edge[1] ? edge[0] : edge[1];
        }
        int time = 0;
        double p = 1.0;
        int currentTo = target;
        while(currentTo != 1) {
            p *= 1 / (double)path[from[currentTo - 1] - 1];
            time++;
            currentTo = from[currentTo - 1];
        }
        if (time > t) {
            return 0;
        } else if (time == t) {
            return p;
        } else {
            if (path[target - 1] == 0) {
                return p;
            } else {
                return 0;
            }
        }
    }
}
```
空间上用了两个长度为n的array，时间上遍历一遍长度为n-1的edge，遍历一遍节点至多为n的路径
![截屏2020-03-08下午1.37.31.png](https://pic.leetcode-cn.com/d4391fe660e90d27436c490c0d0bd06ee4d9141dc01a2c070c31bb28e26b910a-%E6%88%AA%E5%B1%8F2020-03-08%E4%B8%8B%E5%8D%881.37.31.png)
时间复杂度:O(n);
空间复杂度:O(n);
