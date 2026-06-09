```
第一步常规做法

    /**
     * 第一个开始的索引 肯定是gas[i] >= cost[i]
     * 先遍历找每一个这样的i 然后有三个数值 时刻保持 pre + gas[i] - cost[i] >= 0
     * pre 初始值为0 迭代 pre = pre + gas[i] - cost[i]
     * @param gas
     * @param cost
     * @return
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length;
        List<Integer> startList = new ArrayList<>();
        for(int i = 0; i < len; i++){
            if(gas[i] >= cost[i]){
                startList.add(i);
            }
        }
        //没找到肯定不能成功
        if(startList.isEmpty()){
            return -1;
        }

        //对于每一个可能的索引
        for(Integer start : startList){
            int pre = 0;
            boolean success = true;
            //循环索引
            for(int i = 0; i < len; i++){
                int index = (start + i) % len;
                pre = pre + gas[index] - cost[index];
                if(pre < 0){
                    success = false;
                    break;
                }
            }
            if(success){
                return start;
            }
        }
        return -1;
    }


第二步 优化合并
    /**
     * 两步遍历可以合成一步
     * @param gas
     * @param cost
     * @return
     */
    public int canCompleteCircuit2(int[] gas, int[] cost) {
        int len = gas.length;
        for(int i = 0; i < len; i++){
            if(gas[i] >= cost[i]){
                int pre = 0;
                boolean success = true;
                //循环索引
                for(int j = 0; j < len; j++){
                    int index = (i + j) % len;
                    pre = pre + gas[index] - cost[index];
                    if(pre < 0){
                        success = false;
                        break;
                    }
                }
                if(success){
                    return i;
                }
            }
        }
        return -1;
    }

第三部 找到一步遍历的方法 还是利用通项公式 只不过算起始点的cur需要另外的 更新方法
    /**
     * 再优化一下 开始就计算通项公式 pre + gas[i] - cost[i] >= 0
     * 最后pre要大于等于0 证明能成功
     * 起始点开始为第一个gas[i] - cost[i] >= 0 的i值 然后通过不断更新cur值
     * 最后一个使cur >= 0的最开始的索引 比较绕 比如是这样的序列 1 2 3 -1 4 5  6  -2 7 8 是找到7
     * @param gas
     * @param cost
     * @return
     */
    public int canCompleteCircuit3(int[] gas, int[] cost) {
        int len = gas.length;
        int pre = 0;
        int start = -1;
        int cur = 0;
        for(int i = 0; i < len; i++){
            pre = pre + gas[i] - cost[i];
            if(start >= 0){
                cur = cur + gas[i] - cost[i];
                if(cur < 0){
                    //这个start开始已经到不了其他的节点所以不合法
                    start = -1;
                    cur = 0;
                }
            }else {
                if(gas[i] >= cost[i]){
                    start = i;
                    cur = gas[i] - cost[i];
                }
            }
        }
        if(pre < 0){
            return -1;
        }
        return start;
    }
```