我的思路没有官方题解那么巧妙，具体思路如下：
首先先来判断总里程数和总的油量，如果此时已经得知了油量不够，就没有必要进行下一步的寻找出发点的工作了，直接返回

如果这个阶段得到的结果是可以实现环路，则从第一个点开始，记录当前的油量，逐个站点开始走，如果到某个站点的油量低于0，就说明这个起点行不通，将油量进行初始化，进入下一个出发点开始尝试，具体代码如下：
 public int canCompleteCircuit(int[] gas, int[] cost) {
        int miles = 0;
        int gases = 0;
        for(int i = 0;i<gas.length;i++){
            gases += gas[i];
            miles += cost[i];
        }
        if (miles> gases)
            return -1;
        int remain = 0;
        for (int i = 0;i<gas.length;i++){
            remain = gas[i];
            for (int j = 0;j<gas.length;j++){
                remain -= cost[(i+j)%gas.length];
                if (remain<0)
                    break;
                remain += gas[(i+j+1)%gas.length];
            }
            if (remain >= 0)
                return i;
        }
        return -1;
    }

运行的结果肯定是没有官解那么优秀的，不过我认为这是人脑子想的出来的，刚才上厕所想出来的，就叫“厕所”解法吧hhhh
