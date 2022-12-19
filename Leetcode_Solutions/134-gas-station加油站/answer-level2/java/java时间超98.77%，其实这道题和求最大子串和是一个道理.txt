[53题：求最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)
**与53题的区别是，这题需要求的是最大子串的起始位置。代码几乎没有区别，只需要记录一下起始角标**
```
public int canCompleteCircuit2(int[] gas, int[] cost) {
        //将问题转化为找最大子串的起始位置。
        int result = 0;
        int sum = 0;
        int hasResult = 0;//用于判断是否有跑完全程所需的油
        for (int i = 0; i < gas.length; i++) {
            hasResult +=gas[i]-cost[i];
            if(sum > 0) {
                sum += gas[i]-cost[i];
            } else {
                sum = gas[i]-cost[i];
                result = i;
            }
        }

        return hasResult>=0? result:-1;
    }
```
共一次遍历，故时间复杂度为O（n）,空间复杂度O（1）。